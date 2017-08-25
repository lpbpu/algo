package main

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var p1,p2 *ListNode
	var l3 ListNode
	var addtional int

	l3.Next=nil

	p1=l1.Next
	p2=l2.Next
	addtional=0

	for ;; {
		a1:=0
		a2:=0
		flag:=0

		if p1!=nil{
			a1=p1.val
			p1=p1.Next
			flag=1
		}

		if p2!=nil{
			a2=p2.val
			p2=p2.Next
			flag=1
		}


		if flag==0 {
			if addtional==1 {
				addtail(&l3,1)
			}
			break
		}


		add:=a1+a2+addtional
		if add>=10{
			add=add-10
			addtional=1
		}else{
			addtional=0
		}

		addtail(&l3,add)

	}

	return &l3
}

func main(){
	var l1,l2 ListNode
	var l3 *ListNode
	
	l1.Next=nil
	l2.Next=nil

	addtail(&l1,2)
	addtail(&l1,4)
	addtail(&l1,3)

	addtail(&l2,5)
	addtail(&l2,6)
	addtail(&l2,4)

	travel(&l1)
	travel(&l2)

	l3=addTwoNumbers(&l1,&l2)
	
	travel(l3)
	
}
