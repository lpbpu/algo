package main
import "fmt"

func hasCycle(head *ListNode)bool {
	var slow,fast *ListNode

	flag:=false
	slow=head.Next
	if slow==nil {
		return flag
	}

	fast=slow.Next

	for slow!=nil && fast!=nil {
		if slow==fast {
			return true
		}

		slow=slow.Next
		if fast.Next==nil {
			break
		}
		fast=fast.Next.Next

	}

	return flag



}


func hasCycle1(head *ListNode)bool {
	var slow,fast *ListNode;
	slow=head
	fast=head
	
	for fast.Next!=nil && fast.Next.Next!=nil {
		slow=slow.Next
		fast=fast.Next.Next

		if slow==fast {
			return true
		}
	}

	return false


}


func main(){
	var l1 ListNode
	var l2,l3 *ListNode
	l1.Next=nil

	addtail(&l1,1)
	addtail(&l1,2)
	addtail(&l1,3)
	addtail(&l1,4)
	addtail(&l1,5)

	l2=getitem(&l1,5)
	l3=getitem(&l1,2)

	l2.Next=l3

	flag:=hasCycle(&l1)
	flag1:=hasCycle1(&l1)



	fmt.Println("The list hascycle:",flag)
	fmt.Println("The list hascycle1:",flag1)

}
