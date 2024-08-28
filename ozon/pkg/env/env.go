package env

import "os"

func GetEnvFile() (res string) {
	if len(os.Args) >= 2 {
		res = os.Args[1]
	} else {
		res = ".env"
	}
	return
}
