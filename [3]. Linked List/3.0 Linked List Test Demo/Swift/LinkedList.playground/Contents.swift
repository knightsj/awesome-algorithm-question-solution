//  Created by JunsW
//  last checked with Xcode 9.4.1 (9F2000) & Xcode 10.0 Beta4

//: # 链表相关算法 Swfit4.2 实现
import Foundation

class Node {
    var value: Int
    var next: Node?
    
    init(value: Int) {
        self.value = value
    }
    
    func copy() -> Node {
        let node = Node(value: value)
        node.next = next
        return node
    }
}

extension Node: CustomStringConvertible { // 测试3.1的时候记得注释掉这段
    var description: String {
        return String(value)
    }
}

class LinkedList {
    var head: Node? = Node(value: 1)
    
    init() {
        head!.next = Node(value: 2)
        head!.next!.next = Node(value: 3)
        head!.next!.next!.next = Node(value: 4)
    }
    
    func remove(node: inout Node?) {
        if let n = node {
            if let next = n.next {
                n.value = next.value
                n.next = next.next
            } else {
                node = nil
            }
        }
    }
}
extension LinkedList: CustomStringConvertible {
    var description: String {
        var text = "List: ["
        var pointer = head
        while let node = pointer {
            text += String(node.value) + (node.next == nil ? "" : " -> ")
            pointer = node.next
        }
        text += "]"
        return text
    }
}
let list = LinkedList()

/*:
 ## 3.1 Linked List Cycle (链表是否有环)
 ### Question
 检查链表是否有环
 ### Solution
 */
extension LinkedList {
    func makeACircle() { // 注释掉19-23行 45-56行 以及3.6的实现
        head?.next?.next?.next?.next = head?.next?.next
    }
    func hasCircle() -> Bool { // 单链表
        var fastPointer = head
        var slowPointer = head
        
        while let fast = fastPointer, let slow = slowPointer {
            fastPointer = fast.next?.next
            slowPointer = slow.next
            if fastPointer === slowPointer {
                return true
            }
        }
        return false
    }
}

//list.makeACircle()
//print(list.hasCircle())


///*:
// ## 3.2 Intersection Of Two Linked Lists (两个链表是否有交点)
//
// ### Question
// 奇数偶数index的节点分在链表两侧 保留原有顺序 右侧为偶数
// ### Solution
// */
extension LinkedList {
    func findIntersection(with anotherListHead: Node?) -> Node? {
        guard head != nil, anotherListHead != nil else { return nil }
        
        var pointerA = head
        var pointerB = anotherListHead

        while pointerA?.value != pointerB?.value {
            pointerA = pointerA == nil ? anotherListHead : pointerA?.next
            pointerB = pointerB == nil ? head : pointerB?.next
        }
        return pointerA
    }
}

//let listHead = Node(value: 5)
//listHead.next = Node(value: 2)
//listHead.next?.next = Node(value: 3)
//print(list.findIntersection(with: listHead) ?? "没有交点")

///*:
// ## 3.3 Reverse Linked List（反转链表）
//
// ### Question
// 反转链表
// ### Solution
// */
//
extension LinkedList {
    func reversed() {
        /// nodeA.next 指向上一级 nodeB
        func reverse(node a: Node?, previousNode b: Node?) -> Node? {
            if let node = a {
                let nextNode = node.next
                if nextNode == nil { head = node }
                node.next = b
                return reverse(node: nextNode, previousNode: node)
            } else { return b }
        }
        reverse(node: head, previousNode: nil)
    }
}

//print(list)
//list.reversed()
//print(list)

/*:
 ## 3.4 Merge Two Linked List（合并两个有序链表）

 ### Question
 合并两个有序链表
 ### Solution
 */

extension LinkedList {
    func splice(with anotherListHead: Node){
        func mergeTwoLists(nodeA: Node?, nodeB: Node?) -> Node? {
            if let a = nodeA, let b = nodeB {
                if a.value < b.value {
                    a.next = mergeTwoLists(nodeA: a.next, nodeB: b)
                    return a
                } else {
                    b.next = mergeTwoLists(nodeA: b.next, nodeB: a)
                    return b
                }
            } else {
                return nodeA == nil ? nodeB : nodeA
            }
        }

        head = mergeTwoLists(nodeA: head, nodeB: anotherListHead)
    }
}
//let listHead = Node(value: 1)
//listHead.next = Node(value: 2)
//listHead.next?.next = Node(value: 3)
//print(list)
//list.splice(with: listHead)
//print(list)

/*:
 ## 3.5 Find The Kth Node To Tail in Linked List (找到倒数第k个节点)
 ### Question
 找到倒数第k个节点
 ### Solution
 */

extension LinkedList {
    func node(toTail distance: Int) -> Node? {
        var pointerA = head
        var pointerB = head
        for _ in 0 ..< distance {
            if let pointer = pointerA {
                pointerA = pointer.next
            } else { return nil }
        }

        while let pointer = pointerA {
            pointerA = pointer.next
            pointerB = pointerB?.next
        }
        return pointerB
    }
}

//print(list)
//print(list.node(toTail: 2) ?? "")

/*:
 ## 3.6 Recursively Print Linked List (倒序打印链表)
 ### Question
 倒序打印链表
 ### Solution
 */
extension LinkedList {
    func printReversely() {
        var text = "Reversed List: ["
        func print2(node: Node?) { // 函数名如果print xcode 10.0 编译器报错
            if let pointer = node {
                if let nextPointer = pointer.next {
                    print2(node: nextPointer)
                }
                text += pointer.description + (node === head ? "]" : " -> ")
            }
        }
        print2(node: head)
        print(text)
    }
}

//print(list)
//list.printReversely()

/*:
 ## 3.7 Remove Nth From End Of Linkded List (删除倒数第N个节点)
 ### Question
 删除某个值等于给定值的节点
 ### Solution
 */

extension LinkedList {
    func removeNode(ToTail distance: Int) -> Node? {
        guard distance > 0 else { return nil }
        var pointerA = head
        var pointerB = head
        for _ in 1 ... distance+1 {
            if let pointer = pointerA {
                pointerA = pointer.next
            } else { return nil }
        }
        
        while let pointer = pointerA {
            pointerA = pointer.next
            pointerB = pointerB?.next
        }
        pointerB?.next = pointerB?.next?.next
        return pointerB
    }
}

//print(list)
//print(list.removeNode(ToTail: 1))
//print(list)

/*:
 ## 3.8 Delete Node in a Linked List (删除某个值等于给定值的节点)
 ### Question
 1. 链表至少有两个值
 2. 每个值唯一
 3. 给定的值肯定存在于链表中并且不是最后一个
 4. 函数无返回值
 ### Solution
 */

extension LinkedList {
    func remove(node: Node?) {
        node?.value = (node?.next?.value)!
        node?.next = node?.next?.next
    }
}

//print(list)
//list.remove(node: list.head?.next)
//print(list)
/*:
 ## 3.9 Remove Duplicates I（删除重复节点）
 ### Question
 删除重复节点 1,1,2,3 => 1,2,3
 ### Solution
 */

extension LinkedList {
    func removeDuplicatesI() {
        var pointer = head

        while let p = pointer, let pN = p.next{
            if p.value == pN.value{
                p.next = pN.next
            } else {
                pointer = p.next
            }
        }
    }
}
//list.head?.next?.value = 1
//list.head?.next?.next?.value = 1
//print(list)
//list.removeDuplicatesI()
//print(list)

/*:
 ## 3.10 Remove Duplicates II （删除值等于给定值的所有节点）
 ### Question
 删除有重复数值的节点 1，1，2，3 => 2,3
 ### Solution
 */
extension LinkedList {
    func removeDuplicatesII() -> Node? {
        var pointer = head
        
        func compareTwoNodes(a: Node?, b: Node?) {
            if a?.value == b?.value {
                a?.next = b?.next
                compareTwoNodes(a: a, b: a?.next)
            }
        }
        
        while let p = pointer {
            if p.value == p.next?.value {
                compareTwoNodes(a: p, b: p.next)
                if let next = p.next {
                    p.value = next.value
                    p.next = next.next
                } else {
                    if pointer === head { head = nil }
                    else { pointer = nil }
                }
            } else {
                pointer = p.next
            }
        }
        return head
    }
}

//list.head?.next?.value = 1
//list.head?.next?.next = nil
////list.head?.next?.next?.value = 1
//print(list)
//list.removeDuplicatesII()
//print(list)

/*:
 ## 3.11 Remove Linked List Elements(移除链表元素)
 ### Question
 移除单链表中的给定值的节点
 ### Solution
 */

extension LinkedList {
    func remove(value: Int) {
        var pointer = head
        var previous: Node? = nil
        while let node = pointer {
            if node.value == value {
                if let next = node.next {
                    node.value = next.value
                    node.next = next.next
                } else {
                    previous?.next = nil
                    pointer = nil
                }
            } else {
                previous = node
                pointer = node.next
            }
        }
    }
}

//list.head?.next?.next?.next?.next = Node(value: 2)
//print(list)
//list.remove(value: 2)
//print(list)

/*:
 ## 3.12 Partition Linked List (划分链表)
 ### Question
 将小于和大于给定值的节点划分到链表两侧 保留原有顺序 右侧大于等于
 ### Solution
 */
extension LinkedList {
    func portition(at value: Int) {
//        guard let head = head else { return }
//        var pointer: Node? = head
//        var leftLinkeHead: Node? = head
//        var previous: Node? = nil
//
//        while let p = pointer {
//            if p.value < value {
////                remove(node: &pointer)
//                previous?.next = p.next
//                let tmp = leftLinkeHead?.next
//                leftLinkeHead?.next = pointer
//                pointer?.next = tmp
//
//
//                leftLinkeHead = p
//            }
//            pointer = p.next
//            previous = p
//
//        }
        let h1 = Node(value: 0)
        let h2 = Node(value: 0)
        var l1: Node? = h1
        var l2: Node? = h2
        var pointer = head
        
        while let p = pointer {
            if p.value < value {
                l1?.next = p
                l1 = p
            } else {
                l2?.next = p
                l2 = p
            }
            pointer = pointer?.next
        }
        l2?.next = nil
        l1?.next = h2.next
        head = h1.next
    }
}
//list.head?.next?.next?.next?.next = Node(value: 2)
//list.head?.next?.next?.next?.next?.next = Node(value: 4)
//print(list)
//list.portition(at: 3)
//print(list)

/*:
 ## 3.13 Odd Even List （奇偶链表）

 ### Question
 奇数偶数index的节点分在链表两侧 保留原有顺序 右侧为偶数
 ### Solution
 */
extension LinkedList {
    func oddEven() {
        guard head != nil else { return }
        
        var odd = head
        var even = head!.next
        let evenHead = even
        
        while let e = even, let _ = e.next {
            odd?.next = odd?.next?.next
            e.next = e.next?.next
            odd = odd?.next
            even = e.next
        }
        odd?.next = evenHead
    }
}

//print(list)
//list.oddEven()
//print(list)
