package main

func deleteDuplicates(head *ListNode) *ListNode {
	var cur *ListNode
	cur=head.Next

	if cur==nil {
		return head
	}

	for cur.Next!=nil {
		if cur.val==cur.Next.val {
			cur.Next=cur.Next.Next
		}else{
			cur=cur.Next
		}

	}

	return head
}

func main() {
	var l1 ListNode
	var l2 *ListNode

	l1.Next=nil

	addtail(&l1,1)
	addtail(&l1,1)
	addtail(&l1,2)
	addtail(&l1,3)
	addtail(&l1,3)


	l2=deleteDuplicates(&l1)

	travel(l2)

}
