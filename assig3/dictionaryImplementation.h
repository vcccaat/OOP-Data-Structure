// SUBMIT THIS FILE


    //copy constructor
    //deep copy is required
    template<typename K, typename V>
    Dictionary<K,V>::Dictionary(const Dictionary& another)
    {
    	*this = another;
    }

    //if there exists an item with the given key in the dictionary,
    //return a reference to its value
    //otherwise add the new item with that key to the dictionary and set its value to 0 by assignment
    //i.e. something like the following
    //           array[newSize-1].value = 0; 
    //note that the array should always be just big enough to cotain all the items
    //and that the new item is always added to the end of the array, hence the index newSize-1
    //that also means that everytime you add a new item, you need to increase the size of the array by 1
    template<typename K, typename V>
    V& Dictionary<K,V>::operator[](K key) 
    {
    	
    	for (int i = 0; i < size; i++)
    	{
    		if (array[i].key == key) 
    		{
    			return array[i].value;
    		}
    	}

    	KeyValue* kv = new KeyValue [size+1];
    	for (int i =0; i < size; i++)
    	{
    		kv[i] = array[i];
    	}

    	kv[size].value = 0;
		kv[size].key = key;
        delete [] array;
		array = kv;
		size++;

		return array[size-1].value;
    }

    //deep assignment operator
    //remember to check for self-assignment first
    template<typename K, typename V>
    Dictionary<K,V>& Dictionary<K,V>::operator=(const Dictionary& another)
    {
    	
    	if (this != &another)
    	{	
    		KeyValue* kv = new KeyValue [another.size];
    		for (int i =0; i < another.size; i++)
	    	{
	    		kv[i] = another.array[i];
	    	}
            delete [] array;
	    	array = kv;
    		size = another.size;
    	}	
    	return *this;
    }


    //return a list of keys in the exact order they are stored in the dictionary's array
    //you need to dynamically create an array of K and return it in this function
    //however, you do NOT need to delete it here in this function/class
    //the caller of this function has the responsibility of deleting the returned array after it's done using it
    template<typename K, typename V>
    K* Dictionary<K,V>::getKeyList() const
    {
    	K* keylst = new K [size];
    	for (int i =0; i<size; i++)
    	{
    		keylst[i] = array[i].key; 
    	}
    	return keylst;
    }

    //same as above, but for values
    template<typename K, typename V>
    V* Dictionary<K,V>::getValueList() const
    {
    	V* valuelst = new V [size];
    	for (int i =0; i<size; i++)
    	{
    		valuelst[i] = array[i].value;  
    	}
    	return valuelst;
    }

    //delete the array
    //set array to NULL
    //set size to 0
    template<typename K, typename V>
    void Dictionary<K,V>::clean()
    {    
        delete [] array;
        array = NULL;
    	size = 0;
    }
