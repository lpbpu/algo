package main
import "fmt"
import "strings"

func lengthOfLongestSubstring(s string) int {
	var longest,current string
	length:=len(s)	

	for i:=0;i<length;i++ {
		index:=strings.IndexByte(current,s[i])
		if index>=0 {
			if len(current)>len(longest) {
				longest=current
				current=string(s[i])
			}

		}else{
			current+=string(s[i])
		}	

	}
	return len(longest)


}

func main(){
	s1:="abcabcbb"
	s2:="bbbbb"
	s3:="pwwkew"
	
	fmt.Println(s1+":",lengthOfLongestSubstring(s1))
	fmt.Println(s2+":",lengthOfLongestSubstring(s2))
	fmt.Println(s3+":",lengthOfLongestSubstring(s3))


}
