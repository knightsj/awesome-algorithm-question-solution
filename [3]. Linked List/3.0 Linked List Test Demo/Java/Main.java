



class ListNode {

      int val;
      ListNode next;

      ListNode(int x) {
          val = x;
          next = null;
      }
}


public class Main {


    public static void main(String[] args) {

        System.out.println("Hello World!");
    }


    public boolean hasCycle(ListNode head) {

        ListNode slowerNode = head;
        ListNode fasterNode = head;

        while ( slowerNode != null && fasterNode != null && fasterNode.next != null ){

            slowerNode = slowerNode.next;
            fasterNode = fasterNode.next.next;

            if (slowerNode == fasterNode){
                return true;
            }
        }

        return false;
    }


    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        int lengthA = _calculateLinkedListLength(headA);
        int lengthB = _calculateLinkedListLength(headB);

        int n = lengthA - lengthB;

        ListNode pA = headA;
        ListNode pB = headB;

        for ( int i = 0; i < Math.abs(n); i++){

            if (n > 0){
                pA = pA.next;
            }else {
                pB = pB.next;
            }
        }

        while (pA != null && pB != null){

            if ( pA == pB ){
                return pB;
            }

            pA = pA.next;
            pB = pB.next;
        }

        return null;

    }

    private static int _calculateLinkedListLength( ListNode head ){

        int count = 0;

        while ( head != null ){

            count ++;

            head = head.next;
        }

        return count;
    }


    public static ListNode reverseList(ListNode head) {

        ListNode preNode = null;
        ListNode curNode = head;

        while ( curNode != null ){

            ListNode nextNode = curNode.next;

            curNode.next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }

        return preNode;
    }


    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        if ( l1 == null ){
            return l2;
        }

        if ( l2 == null ){
            return l1;
        }

        ListNode mergedNode = null;

        if ( l1.val < l2.val ){

            mergedNode = l1;
            mergedNode.next = mergeTwoLists(mergedNode.next, l2);

        }else{

            mergedNode = l2;
            mergedNode.next = mergeTwoLists(l1, mergedNode.next);
        }

        return mergedNode;
    }


    public static ListNode FindKthToTail(ListNode pListHead,  int k) {


        if (pListHead == null){
            return null;
        }

        ListNode pHead = pListHead;
        ListNode pBehind = null;

        for ( int i = 0; i < k -1; i++){

            if (pHead.next != null){
                pHead = pHead.next;
            }else {
                return null;
            }
        }

        pBehind = pListHead;

        while(pHead.next != null){
            pHead = pHead.next;
            pBehind = pBehind.next;
        }

        return pBehind;
    }

    public static void PrintListReversingly(ListNode pHead)
    {
        if(pHead != null)
        {
            if (pHead.next != null)
            {
                PrintListReversingly(pHead.next);
            }

            System.out.println(pHead.val);
        }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {

        if( head == null || head.next == null){
            return null;
        }

        ListNode firstNode = head;
        ListNode secondNode = head;

        for(int i = 0; i < n; i++){
            firstNode = firstNode.next;
        }

        //1,2,3,4,5 n = 4
        if(firstNode == null){
            return head.next;
        }

        while(firstNode.next != null)
        {
            firstNode = firstNode.next;
            secondNode = secondNode.next;
        }

        secondNode.next = secondNode.next.next;

        return head;

    }

    public void deleteNode(ListNode node) {

        if ( node == null || node.next == null)  {
            return;
        }

        node.val = node.next.val;
        node.next = node.next.next;
    }


    public ListNode deleteDuplicates(ListNode head) {


        if ( head == null || head.next == null){
            return head;
        }

        ListNode curNode = head;

        while (curNode.next != null){

            if (curNode.val == curNode.next.val){

                //delNode is the node to delete
                ListNode delNode = curNode.next;
                curNode.next = delNode.next;

            } else{

                curNode = curNode.next;

            }
        }

        return head;

    }

    public ListNode deleteAllDuplicates(ListNode head) {

        if (head == null) {
            return null;
        }

        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode pre = fakeHead;
        ListNode cur = head;

        while (cur != null) {

            while (cur.next != null && cur.val == cur.next.val) {
                cur = cur.next;
            }

            if (pre.next == cur) {
                //pre is next to cur
                pre = pre.next;

            } else {

                pre.next = cur.next;

            }
            //move cur
            cur = cur.next;
        }
        return fakeHead.next;
    }

    public ListNode removeElements(ListNode head, int val) {

        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        ListNode cur = dummyHead;

        while (cur.next != null){

            if (cur.next.val == val){

                ListNode delNode = cur.next;
                cur.next = delNode.next;

            } else{

                cur = cur.next;

            }
        }

        ListNode returnNode = dummyHead.next;

        return returnNode;
    }


    public ListNode partition(ListNode head, int x) {


        if (head == null || head.next == null){
            return head;
        }

        ListNode left = new ListNode(-1);
        ListNode p = left;

        ListNode right = new ListNode(-1);
        ListNode q = right;

        while(head != null){

            if( head.val < x){

                p.next = head;
                p = p.next;

            }else{

                q.next = head;
                q = q.next;
            }

            head = head.next;
        }

        q.next = null; //right end
        p.next = right.next;//left end
        return left.next;


    }


    public ListNode oddEvenList(ListNode head) {

        if (head == null || head.next == null){
            return head;
        }

        ListNode left = new ListNode(-1);
        ListNode p = left;

        ListNode right = new ListNode(-1);
        ListNode q = right;

        int index = 1;

        while( head != null ){

            if(__partitionCondition(index)){

                p.next = head;
                p = p.next;

            }else{
                q.next = head;
                q = q.next;
            }

            head = head.next;

            index++;
        }

        q.next = null; //right end
        p.next = right.next;//left end
        return left.next;
    }

    private boolean __partitionCondition(int val){

        if (val % 2 == 1){
            return true;
        } else {
            return false;
        }
    }


}
