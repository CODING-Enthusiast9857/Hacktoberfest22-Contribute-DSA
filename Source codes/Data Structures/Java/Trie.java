public class Trie {
    static final int size = 26;
    static class TrieNode{
        TrieNode[] children = new TrieNode[size];
        boolean isEndOfWord;
        TrieNode(){
            isEndOfWord = false;
            for(int i = 0; i < size; i++){
                children[i] = null;
            }
        };

        static TrieNode root;

        static void insert(String key){
            int level;
            int length = key.length();
            int index;

            TrieNode pCrawl = root;
            for(level = 0; level < length; level++){
                index = key.charAt(level) - 'a';
                if (pCrawl.children[index] == null)
                    pCrawl.children[index] = new TrieNode();

                pCrawl = pCrawl.children[index];
            }
            pCrawl.isEndOfWord = true;
        }

        static boolean search(String key){
            int level;
            int length = key.length();
            int index;

            TrieNode pCrawl = root;

            for(level = 0; level < length; level++){
                index = key.charAt(level) - 'a';

                if (pCrawl.children[index] == null)
                    return false;

                pCrawl = pCrawl.children[index];
            }
            return (pCrawl.isEndOfWord);
        }

        public static void main(String[] args) {
            String[] keys = {"the", "a", "there", "answer", "any",
                    "by", "bye", "their"};
            String[] output = {"Not present in trie", "Present in trie"};

            root = new TrieNode();

            // Construct trie
            int i;
            for (i = 0; i < keys.length ; i++)
                insert(keys[i]);

            // Search for different keys
            if(search("the"))
                System.out.println("the --- " + output[1]);
            else System.out.println("the --- " + output[0]);

            if(search("these"))
                System.out.println("these --- " + output[1]);
            else System.out.println("these --- " + output[0]);

            if(search("their"))
                System.out.println("their --- " + output[1]);
            else System.out.println("their --- " + output[0]);

            if(search("thaw"))
                System.out.println("thaw --- " + output[1]);
            else System.out.println("thaw --- " + output[0]);
        }
    }
}
