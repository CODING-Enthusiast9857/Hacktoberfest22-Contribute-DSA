import java.util.*;

class TrieNode {
	boolean endOfWord;
	Map<Character, TrieNode> children;

	public TrieNode() {
		endOfWord = false;
		children = new HashMap<>();
	}
}

class Trie {
	TrieNode root;
	public Trie() {
		root = new TrieNode();
	}

	public void insert(String word) {
		TrieNode temp = root;
		for (char letter : word.toCharArray()) {
			if (!temp.children.containsKey(letter)) {
				temp.children.put(letter, new TrieNode());
			}
			temp = temp.children.get(letter);
		}
		temp.endOfWord = true;
	}

	public boolean search(String word) {
		TrieNode temp = root;

		for (char letter : word.toCharArray()) {
			if (temp.children.containsKey(letter)) {
				temp = temp.children.get(letter);
			} else {
				return false;
			}
		}
		return temp.endOfWord;
	}

	public boolean startsWith(String prefix) {
		TrieNode temp = root;

		for (char letter : prefix.toCharArray()) {
			if (temp.children.containsKey(letter)) {
				temp = temp.children.get(letter);
			} else {
				return false;
			}
		}
		return true;
	}
}
