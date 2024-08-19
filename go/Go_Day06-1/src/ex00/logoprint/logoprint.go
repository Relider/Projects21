package logoprint

import (
	"image"
	"image/color"
	"image/png"
	"os"
)

const (
	WIDTH  int = 400
	HEIGHT int = 400
)

var upLeft = image.Point{0, 0}
var lowRight = image.Point{WIDTH, HEIGHT}

var colorGreen = color.RGBA{195, 255, 104, 0xff}
var colorRed = color.RGBA{245, 0, 0, 0xff}
var colorPink = color.RGBA{251, 231, 239, 0xff}

func CreateLogo(fileName string) error {
	img := image.NewRGBA(image.Rectangle{upLeft, lowRight})

	for x := 0; x < WIDTH; x++ {
		for y := 0; y < HEIGHT; y++ {
			img.Set(x, y, color.White)
		}
	}
	drawPixel(img)

	f, err := os.Create(fileName)
	png.Encode(f, img)
	return err
}

func drawPixel(img *image.RGBA) {

	for x := 70; x <= 330; x++ {
		for y := 30; y <= 370; y++ {
			img.Set(x, y, colorRed)
		}
	}

	for x := 110; x <= 290; x++ {
		for y := 190; y <= 210; y++ {
			img.Set(x, y, colorGreen)
		}
	}

	for x := 110; x <= 130; x++ {
		for y := 50; y <= 350; y++ {
			img.Set(x, y, colorGreen)
		}
	}

	for x := 270; x <= 290; x++ {
		for y := 50; y <= 350; y++ {
			img.Set(x, y, colorGreen)
		}
	}

}
