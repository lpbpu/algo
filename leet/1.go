package main
import "fmt"


func twoSum (num []int,target int) []int {
	b:=make([]int,2)

	for i:=0;i<len(num);i++ {
		cmp:=target-num[i]
		for j:=0;j<len(num);j++ {
			if j==i {
				continue
			}
			if num[j]==cmp {
				b[0]=i
				b[1]=j
				return b
			}
		}
	}

	return b
}

func main() {
	nums:=[]int {2,7,11,15}
	//nums:=make([]int,4)
	//nums[0]=2
	//nums[1]=7
	//nums[2]=11
	//nums[3]=15

	var target int = 9

	result:=twoSum(nums,target)
	fmt.Println("result:",result)
}
