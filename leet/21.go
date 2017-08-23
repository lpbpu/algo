package main

/* require link.go */


func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var newlst ListNode
	var l3 *ListNode

	l3=&newlst
	l3.Next=nil

	l1=l1.Next
	l2=l2.Next

	for l1!=nil && l2!=nil {
		if l1.val<l2.val {
			l3.Next=l1
			l1=l1.Next
		}else{
			l3.Next=l2
			l2=l2.Next
		}

		l3=l3.Next
	}


	if l1!=nil {
		l3.Next=l1
	}else{
		l3.Next=l2
	}

	return &newlst
}

func main(){
	var l1,l2 ListNode
	l1.Next=nil
	l2.Next=nil

	addtail(&l1,1)
	addtail(&l1,3)
	addtail(&l1,5)

	addtail(&l2,2)
	addtail(&l2,4)
	addtail(&l2,6)
	addtail(&l2,8)


	l3:=mergeTwoLists(&l1,&l2)

	travel(l3)


}
