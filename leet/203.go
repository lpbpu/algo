package main

func removeElements(head *ListNode, val int) *ListNode {
   	point:=head

	for point.Next!=nil {
		if point.Next.val==val {
			point.Next=point.Next.Next
		}else{
			point=point.Next
		}
	}
	return head
 
}

func main(){
	var l1 ListNode
	var l2 *ListNode

	l1.Next=nil

	addtail(&l1,1)
	addtail(&l1,2)
	addtail(&l1,6)
	addtail(&l1,3)
	addtail(&l1,4)
	addtail(&l1,5)
	addtail(&l1,6)


	l2=removeElements(&l1,6)

	travel(l2)


}
