class DoublyLinkedListNode{
    DoublyLinkedListNode next, prev;
    int data;

    DoublyLinkedListNode(int data){
        this.data = data;
        next = null;
        prev = null;
    }
}

public class HashTableDoublyLinkedLists {
    DoublyLinkedListNode[] hashtable;

    int size;

    HashTableDoublyLinkedLists(int hashtablesize) {
        hashtable = new DoublyLinkedListNode[hashtablesize];
        size = 0;
    }

    public boolean isEmpty() {
         return size == 0;
    }

    public void clear(){
         int len = hashtable.length;
         hashtable = new DoublyLinkedListNode[len];
         size = 0;
    }

    public int getSize() {
        return size;
    }

    public void insert(int value) {
        size++;
        int position = hash(value);
        DoublyLinkedListNode node = new DoublyLinkedListNode(value);
        DoublyLinkedListNode start = hashtable[position];

        if (hashtable[position] == null)
            hashtable[position] = node;
        else {
            node.next = start;
            start.prev = node;
            hashtable[position] = node;
        }
    }

    public void remove(int value) {
        try {
            int position = hash(value);
            DoublyLinkedListNode start = hashtable[position];
            DoublyLinkedListNode end = start;
            if (start.data == value) {
                size--;
                if (start.next == null) {
                    // removing the value
                    hashtable[position] = null;
                    return;
                }
                start = start.next;
                start.prev = null;
                hashtable[position] = start;
                return;
            }
            while (end.next != null
                    && end.next.data != value)
                end = end.next;
            if (end.next == null) {
                System.out.println("\nElement not found\n");
                return;
            }

            size--;

            if (end.next.next == null) {
                end.next = null;
                return;
            }

            end.next.next.prev = end;
            end.next = end.next.next;

            hashtable[position] = start;
        } catch (Exception e) {
            System.out.println("\nElement not found\n");
        }

    }

    private int hash(Integer x) {
        int hashValue = x.hashCode();

        hashValue %= hashtable.length;

        if (hashValue < 0)
            hashValue += hashtable.length;

        return hashValue;
    }

    public void printHashTable() {
        System.out.println();
        for (int i = 0; i < hashtable.length; i++) {
            System.out.print("At " + i + ":  ");
            DoublyLinkedListNode start = hashtable[i];
            while (start != null) {
                System.out.print(start.data + " ");
                start = start.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        HashTableDoublyLinkedLists ht = new HashTableDoublyLinkedLists(5);
        ht.insert(1);
        ht.insert(2);
        ht.printHashTable();
    }
}
