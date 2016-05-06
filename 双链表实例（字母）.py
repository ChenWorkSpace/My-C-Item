# -*- coding: cp936 -*-
__metaclass__=type


class Node:
    def __init__(self):
        self.data=0
        self.prior=self
        self.next=self

    def setdata(self,data):
        self.data=data

    def getdata(self):
        print self.data


def nextnode(node,num):
    for i in range(num):
        node=node.next

    for i in range(26):
        print chr(node.data),
        node=node.next
    print ' '
        
def priornode(node,num):
    for i in range(num):
        node=node.prior

        
    for i in range(26):
        print chr(node.data),
        node=node.next
    print ' '
        
if __name__=='__main__':
    p=Node()
    head=Node()
    p=head
    for i in range(65,91):
        s=Node()
        s.data=i
        p.next=s
        s.prior=p
        p=s
    s.next=head.next
    head.next.prior=s
    head=head.next
    for i in range(26):
        print chr(head.data),
        head=head.next
    print ' '
    t=True
    
    while(t):
        i=raw_input('请输入一个数字\n')
        if i=='end':
            t=False
        elif i<0 :
            nextnode(head,int(i))
        else :
            priornode(head,int(i))
            
            
            

        
