package getElement

import (
	"fmt"
	"strconv"
	"unsafe"
)

func getElement(arr []int, idx int) (int, error) {
	var err error = nil
	result := 0
	if len(arr) == 0 {
		err = fmt.Errorf("empty slice")
	} else if idx < 0 || idx >= len(arr) {
		err = fmt.Errorf("idx out of bounds: " + strconv.Itoa(idx))
	} else {
		result = *(*int)(unsafe.Pointer(uintptr(unsafe.Pointer(&arr[0])) + unsafe.Sizeof(int(0))*uintptr(idx)))
	}
	return result, err
}
