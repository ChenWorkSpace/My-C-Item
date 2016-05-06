# -*- coding: cp936 -*-
import time
__metaclass__=type


'''单链表'''
class Node:
    def __init__(self):
        self.data=0
        self.next=self

    def getdata(self):
        print self.data

    def setdata(self,data):
        self.data=data

'''双链表'''

class Dnode:
    def __init__(self):
        self.data=0
        self.next=self
        self.prior=self

    def setdata(self,data):
        self.data=data

    def getdata(self):
        print self.data


        
if __name__=='__main__':
    p=Node()
    head=Node()
    p=head;
    print '单链表'
    time.sleep(1.5)
    for i in range(10):
        s=Node()
        s.data=i
        p.next=s
        p=s

    for i in range(10):
        head=head.next
        print head.data
        
    print '双链表'
    time.sleep(1.5)
    dp=Dnode()
    dhead=Dnode()
    dp=dhead
    for i in range(10):
        s=Dnode()
        s.data=i
        dp.next=s
        s.prior=dp
        dp=s

        
    for i in range(10):
        dhead=dhead.next
        print dhead.data

    print '双链表倒序'
    time.sleep(1.5)
    for i in range(10):
        print dp.data
        dp=dp.prior
        
        
        
  







    


