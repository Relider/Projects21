package main

import (
	"encoding/json"
	"fmt"
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
	var requestBody RequestBody
	log.Println("server get value")
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
		w.WriteHeader(200)
		json.NewEncoder(w).Encode(SuccessResponseBody{
			Thanks: "Thank you!",
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

func main() {
	http.HandleFunc("/buy_candy", buyCandy)
	log.Println("server start work")
	http.ListenAndServe("127.0.0.1:3333", nil)
}
