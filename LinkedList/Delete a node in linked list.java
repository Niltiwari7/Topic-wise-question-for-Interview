class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
        this.next = null;
    }
}

public class Main {
    static void print(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    static Node insertNode(int arr[], Node head) {
        Node tail = null;
        int n = arr.length; 
        for (int i = 0; i < n; i++) {
            Node node = new Node(arr[i]);
            if (head == null) {
                head = node;
                tail = head;
            } else {
                tail.next = node;
                tail = tail.next;
            }
        }
        return head; 
    }

    static Node deleteNode(int i, Node head) {
        Node curr = head;
        int n = getCount(head);

        if (i == 0) {
            return head.next;
        } else if (i == n - 1) {
            while (curr.next != null) {
                curr = curr.next;
            }
            return head;
        } else if (i >= n) {
            return head;
        } else if (i > 0 && i < n - 1) {
            int count = 0;
            while (count < i - 1 && curr.next != null) {
                curr = curr.next;
                count++;
            }
            curr.next = curr.next.next;
        }

        return head;
    }

   
    static int getCount(Node head) {
        int count = 0;
        Node curr = head;
        while (curr != null) {
            count++;
            curr = curr.next;
        }
        return count;
    }

    public static void main(String[] args) {
        Node head = null;
        int[] arr = { 1, 2, 3, 4, 5 };
        head = insertNode(arr, head);
        System.out.println("Original List:");
        print(head);

        int indexToDelete = 2;
        head = deleteNode(indexToDelete, head);

        System.out.println("List after deleting node at index " + indexToDelete + ":");
        print(head);
    }
}
