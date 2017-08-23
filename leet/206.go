package main

func reverseList(head *ListNode) *ListNode {
	var p1,p2,p3 *ListNode
	p1=head
	p2=p1.Next
	
	if p2==nil {
		return head
	}

	p3=p2.Next

	for p3!=nil {
		p2.Next=p1
		p1=p2
		p2=p3
		p3=p3.Next
	}

	p2.Next=p1
	head.Next.Next=nil
	head.Next=p2
	return head
 
}

func main(){
	var l1 ListNode
	var l2 *ListNode
	l1.Next=nil

	addtail(&l1,1)
	addtail(&l1,2)
	addtail(&l1,3)
	addtail(&l1,4)
	addtail(&l1,5)

	l2=reverseList(&l1)

	travel(l2)

}
