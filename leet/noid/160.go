package main
import "fmt"

func getIntersectionNode(node1 *ListNode,node2 *ListNode)*ListNode{
	var p1,p2 *ListNode
	p1=node1.Next
	p2=node2.Next


	for p1!=p2 {
		if p1==nil {
			p1=node2.Next
		}
		p1=p1.Next
		if p2==nil {
			p2=node1.Next
		}
		p2=p2.Next
	}	
	
	return p1
}

func main(){
	var l1,l2 ListNode
//	var l3,l4 *ListNode
	var l5 *ListNode
	

	l1.Next=nil
	l2.Next=nil

	addtail(&l1,1)
	addtail(&l1,2)
	addtail(&l1,3)
	addtail(&l1,4)
	addtail(&l1,5)

	addtail(&l2,6)
	addtail(&l2,7)
	addtail(&l2,8)

//	l3=getitem(&l1,3)
//	l4=getitem(&l2,3)
//	l4.Next=l3

	l5=getIntersectionNode(&l1,&l2)
	if l5==nil{
		fmt.Println("l1 l2 has no intersection")
	}else{
		fmt.Println("l1 l2 has intersection:",l5.val)
	}

}
