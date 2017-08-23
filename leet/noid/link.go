/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

package main
import "fmt"



type ListNode struct {
    val int
    Next *ListNode
}

func addtail(header *ListNode,value int){
	point:=header
	for point.Next!=nil {
		point=point.Next
	}

	var temp ListNode
	temp.val=value
	temp.Next=nil

	point.Next=&temp
}

func travel(header *ListNode){
	point:=header.Next

	for point!=nil {
		fmt.Print(point.val,"->")
		point=point.Next
	}
	fmt.Println("nil")
}

func getitem(head *ListNode,cnt int) *ListNode {
	point:=head

	point=point.Next

	counter:=1
	
	for point!=nil {
		if (counter>=cnt) {
			break
		}

		point=point.Next
		counter=counter+1
	}

	return point

}

/*
func main(){
	var l1 ListNode;
	var l2 *ListNode;
	l1.Next=nil

	addtail(&l1,1)
	addtail(&l1,2)
	addtail(&l1,3)
	addtail(&l1,4)

	travel(&l1)

	l2=getitem(&l1,0)
	fmt.Println("item0:",l2.val)
	l2=getitem(&l1,1)
	fmt.Println("item1:",l2.val)
	l2=getitem(&l1,4)
	fmt.Println("item4:",l2.val)
	l2=getitem(&l1,99)
	fmt.Println("item99:",l2.val)


}*/

