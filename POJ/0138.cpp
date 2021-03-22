Node* copyRandomList(Node* head){
	unordered_map<Node*, Node*> node_map;

	Node *current = head;
	while(current){
		node_map[current] = new Node(current->val);
		current = current->next;
	}

	current = head;
	while(current){
		node_map[current]->next = node_map[current->next];
		node_map[current]->random = node_map[current->random];
		current = current->next;
	}

	return node_map[head];
}