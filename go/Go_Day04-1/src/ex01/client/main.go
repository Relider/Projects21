package main

import (
	"bytes"
	"crypto/tls"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
)

type RequestBody struct {
	Money      int    `json:"money"`
	CandyType  string `json:"candyType"`
	CandyCount int    `json:"candyCount"`
}

type SuccessResponseBody struct {
	Change int    `json:"change"`
	Thanks string `json:"thanks"`
	Error  string `json:"error"`
}

func err_code(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func getClient() (client *http.Client) {
	c, err := tls.LoadX509KeyPair("./cert.pem", "./key.pem")
	err_code(err)
	certs := []tls.Certificate{c}
	if len(certs) == 0 {
		client = &http.Client{}
	} else {
		tr := &http.Transport{
			TLSClientConfig: &tls.Config{
				Certificates: certs,
				InsecureSkipVerify: true,
			},
		}
		client = &http.Client{Transport: tr}
	}
	return
}

func getFlags() (rBody RequestBody) {
	CandyTypePtr := flag.String("k", "", "Candy Type")
	CandyCountPtr := flag.Int("c", 1, "Count of Candy")
	MoneyAmountPtr := flag.Int("m", 0, "Amount of money")
	flag.Parse()
	rBody.CandyType = *CandyTypePtr
	rBody.CandyCount = *CandyCountPtr
	rBody.Money = *MoneyAmountPtr
	return
}

func readServer(data []byte) (sBody SuccessResponseBody) {
	err := json.Unmarshal(data, &sBody)
	err_code(err)
	return
}

func PrintResult(sBody SuccessResponseBody) {
	if sBody.Error == "" {
		fmt.Printf("%s Your change is %d\n", sBody.Thanks, sBody.Change)
	} else {
		fmt.Printf("error: %s\n", sBody.Error)
	}
}

func main() {
	client := getClient()
	rBody := getFlags()
	jsonValue, _ := json.Marshal(rBody)
	resp, err := client.Post("https://127.0.0.1:3333/buy_candy", "application/json", bytes.NewBuffer(jsonValue))
	err_code(err)

	data, err := io.ReadAll(resp.Body)
	err_code(err)
	sBody := readServer(data)
	PrintResult(sBody)
	resp.Body.Close()
}
