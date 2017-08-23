package main
import "fmt"


func reverse(x int) int {
	r:=0
	for x!=0 {
		n:=x%10
		t:=r*10+n
		if t/10!=r {
			return 0
		}
		r=t
		x=(x-n)/10
	}
	return r
}


func main(){
	fmt.Println("reverse 123=",reverse(123))
	fmt.Println("reverse -123=",reverse(-123))
    fmt.Println("reverse 2147483647=",reverse(2147483647))
    fmt.Println("reverse 549755813887=",reverse(549755813887))
    fmt.Println("reverse 9123372036854775879=",reverse(9123372036854775879))

}
