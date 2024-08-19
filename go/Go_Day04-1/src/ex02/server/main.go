package main

import (
	"crypto/tls"
	"crypto/x509"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"
	"os/exec"
)

type RequestBody struct {
	Money      int    `json:"money"`
	CandyType  string `json:"candyType"`
	CandyCount int    `json:"candyCount"`
}

type SuccessResponseBody struct {
	Change int    `json:"change"`
	Thanks string `json:"thanks"`
}

type FailResponseBody struct {
	Error string `json:"error"`
}

var CandyPrices = map[string]int{
	"CE": 10,
	"AA": 15,
	"NT": 17,
	"DE": 21,
	"YR": 23,
}

func err_code(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func buyCandy(w http.ResponseWriter, r *http.Request) {
	log.Println("server gets data")
	var requestBody RequestBody
	err := json.NewDecoder(r.Body).Decode(&requestBody)
	err_code(err)
	if _, ok := CandyPrices[requestBody.CandyType]; !ok {
		w.WriteHeader(400)
		json.NewEncoder(w).Encode(FailResponseBody{
			Error: "Invalid candy type",
		})
		return
	}
	if requestBody.CandyCount < 0 {
		w.WriteHeader(400)
		json.NewEncoder(w).Encode(FailResponseBody{
			Error: "Negative candy count",
		})
		return
	}
	if requestBody.Money >= CandyPrices[requestBody.CandyType]*requestBody.CandyCount {
		cmd := exec.Command("gcc", "../CowSay/CowSay.c", "-o", "CowSay")
		err := cmd.Run()
		err_code(err)
		cmd = exec.Command("./CowSay", "Thank you!")
		stdout, err := cmd.CombinedOutput()
		err_code(err)
		w.WriteHeader(200)
		json.NewEncoder(w).Encode(SuccessResponseBody{
			Thanks: string(stdout),
			Change: requestBody.Money - CandyPrices[requestBody.CandyType]*requestBody.CandyCount,
		})
		return
	} else {
		w.WriteHeader(402)
		diff := CandyPrices[requestBody.CandyType]*requestBody.CandyCount - requestBody.Money
		json.NewEncoder(w).Encode(FailResponseBody{
			Error: fmt.Sprintf("You need %d more money!", diff),
		})
		return
	}
}

func getServer() *http.Server {
	data, err := os.ReadFile("minica.pem")
	err_code(err)
	cp := x509.NewCertPool()
	cp.AppendCertsFromPEM(data)

	tls := &tls.Config{
		ServerName: "candy.tld",
		ClientCAs:  cp,
		ClientAuth: tls.RequireAndVerifyClientCert,
	}

	server := &http.Server{
		Addr:      "127.0.0.1:3333",
		TLSConfig: tls,
	}
	return server
}

func main() {
	http.HandleFunc("/buy_candy", buyCandy)
	server := getServer()
	log.Println("server start work")
	err := server.ListenAndServeTLS("minica.pem", "minica-key.pem")
	err_code(err)
}
