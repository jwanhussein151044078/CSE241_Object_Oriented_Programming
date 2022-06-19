public class tester {
	public static void vector_tester(){
		String[] str = {"jwan","hussein","gtu","CSE241","vise","final","class","java","class","quiz","test","final","hw8"};
		Integer[] arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,2,3,5,8,9};
		vector<Integer> vint1 = new vector<Integer>();
		vector<Integer> vint2 = new vector<Integer>();		
		vint1.add(arr[5]);
		vint1.add(arr[2]);
		vint1.add(arr[14]);
		vint1.add(arr[4]);
		vint1.add(arr[6]);
		vint1.add(arr[13]);
		vint1.add(arr[10]);
		vint1.add(arr[11]);
		iterator<Integer> it1 = vint1.iterator(); 
		vint2.add(arr[0]);
		vint2.add(arr[2]);
		vint2.add(arr[3]);
		vint2.add(arr[5]);
		vint2.add(arr[14]);
		vint2.add(arr[6]);
		iterator<Integer> it2 = vint2.iterator();
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  vector Integer test begin  //////////////\n");
		
		System.out.printf("the initial value of the first vector >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\nthe initial value of the second vector >>");
		while(it2.hasNext()){
			System.out.printf("%s ,",it2.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first vector %d\nthe size of the second vector %d \n",vint1.size(),vint2.size());
		System.out.printf("adding element to the first vector :: %s\n",vint1.add(arr[15]));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first vector >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second vector to first vector :: %s\n",vint1.addAll(vint2));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first vector >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the vector contain the number 1 :: %s\n",vint1.contains(1));
		System.out.printf("the vector contain the second vector :: %s\n",vint1.containsAll(vint2));
		System.out.printf("removing the second array from first array\n");
		vint1.removeAll(vint2);
		it1 = vint1.iterator();
		System.out.printf("the new value of the first vector >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the vector !!!!!!\n");
		vint1.clear();
		System.out.printf("is empty :: %s\n",vint1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  vector Integer test end  //////////////\n\n");
			
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  vector String test begin  //////////////\n");
		vector<String> vstr1 = new vector<String>();
		vector<String> vstr2 = new vector<String>();
		vstr1.add(str[0]);vstr1.add(str[1]);vstr1.add(str[2]);vstr1.add(str[3]);vstr1.add(str[4]);vstr1.add(str[5]);
		vstr1.add(str[6]);vstr1.add(str[7]);vstr1.add(str[8]);vstr1.add(str[9]);
		vstr2.add(str[2]);vstr2.add(str[8]);vstr2.add(str[4]);vstr2.add(str[12]);
		iterator<String> it3 = vstr1.iterator();
		iterator<String> it4 = vstr2.iterator();
		System.out.printf("the initial value of the first vector >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\nthe initial value of the second vector >>");
		while(it4.hasNext()){
			System.out.printf("%s ,",it4.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first vector %d\nthe size of the second vector %d \n",vstr1.size(),vstr2.size());
		System.out.printf("adding element to the first vector :: %s\n",vstr1.add(str[1]));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first vector >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second vector to first vector :: %s\n",vstr1.addAll(vstr2));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first vector >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the vector contain (go) :: %s\n",vstr1.contains("go"));
		System.out.printf("the vector contain the second vector :: %s\n",vstr1.containsAll(vstr2));
		System.out.printf("removing the second array from first array\n");
		vstr1.removeAll(vstr2);
		it3 = vstr1.iterator();
		System.out.printf("the new value of the first vector >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the vector !!!!!!\n");
		vstr1.clear();
		System.out.printf("is empty :: %s\n",vstr1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  vector String test end  //////////////\n");

	}
	public static void ArrayList_tester(){
		String[] str = {"jwan","hussein","gtu","CSE241","vise","final","class","java","class","quiz","test","final","hw8"};
		Integer[] arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,2,3,5,8,9};
		ArrayList<Integer> vint1 = new ArrayList<Integer>();
		ArrayList<Integer> vint2 = new ArrayList<Integer>();		
		vint1.add(arr[5]);
		vint1.add(arr[2]);
		vint1.add(arr[0]);
		vint1.add(arr[5]);
		vint1.add(arr[9]);
		vint1.add(arr[13]);
		vint1.add(arr[19]);
		vint1.add(arr[11]);
		iterator<Integer> it1 = vint1.iterator(); 
		vint2.add(arr[0]);
		vint2.add(arr[12]);
		vint2.add(arr[9]);
		vint2.add(arr[5]);
		vint2.add(arr[4]);
		vint2.add(arr[6]);
		iterator<Integer> it2 = vint2.iterator();
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  ArrayList Integer test begin  //////////////\n");
		
		System.out.printf("the initial value of the first ArrayList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\nthe initial value of the second ArrayList >>");
		while(it2.hasNext()){
			System.out.printf("%s ,",it2.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first ArrayList %d\nthe size of the second ArrayList %d \n",vint1.size(),vint2.size());
		System.out.printf("adding element to the first ArrayList :: %s\n",vint1.add(arr[15]));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first ArrayList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second ArrayList to first ArrayList :: %s\n",vint1.addAll(vint2));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first ArrayList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the ArrayList contain the number 1 :: %s\n",vint1.contains(1));
		System.out.printf("the ArrayList contain the second ArrayList :: %s\n",vint1.containsAll(vint2));
		System.out.printf("removing the second array from first array\n");
		vint1.removeAll(vint2);
		it1 = vint1.iterator();
		System.out.printf("the new value of the first ArrayList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the ArrayList !!!!!!\n");
		vint1.clear();
		System.out.printf("is empty :: %s\n",vint1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  ArrayList Integer test end  //////////////\n\n");
			
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  ArrayList String test begin  //////////////\n");
		ArrayList<String> vstr1 = new ArrayList<String>();
		ArrayList<String> vstr2 = new ArrayList<String>();
		vstr1.add(str[0]);vstr1.add(str[1]);vstr1.add(str[2]);vstr1.add(str[3]);vstr1.add(str[4]);vstr1.add(str[5]);
		vstr1.add(str[6]);vstr1.add(str[7]);vstr1.add(str[8]);vstr1.add(str[9]);
		vstr2.add(str[2]);vstr2.add(str[0]);vstr2.add(str[0]);vstr2.add(str[12]);
		iterator<String> it3 = vstr1.iterator();
		iterator<String> it4 = vstr2.iterator();
		System.out.printf("the initial value of the first ArrayList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\nthe initial value of the second ArrayList >>");
		while(it4.hasNext()){
			System.out.printf("%s ,",it4.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first ArrayList %d\nthe size of the second ArrayList %d \n",vstr1.size(),vstr2.size());
		System.out.printf("adding element to the first ArrayList :: %s\n",vstr1.add(str[1]));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first ArrayList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second ArrayList to first ArrayList :: %s\n",vstr1.addAll(vstr2));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first ArrayList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the ArrayList contain (go) :: %s\n",vstr1.contains("go"));
		System.out.printf("the ArrayList contain the second ArrayList :: %s\n",vstr1.containsAll(vstr2));
		System.out.printf("removing the second array from first array\n");
		vstr1.removeAll(vstr2);
		it3 = vstr1.iterator();
		System.out.printf("the new value of the first ArrayList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the ArrayList !!!!!!\n");
		vstr1.clear();
		System.out.printf("is empty :: %s\n",vstr1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  ArrayList String test end  //////////////\n");

	}
	public static void HashSet_tester(){
		String[] str = {"jwan","hussein","gtu","CSE241","vise","final","class","java","class","quiz","test","final","hw8"};
		Integer[] arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,2,3,5,8,9};
		HashSet<Integer> vint1 = new HashSet<Integer>();
		HashSet<Integer> vint2 = new HashSet<Integer>();		
		vint1.add(arr[0]);
		vint1.add(arr[2]);
		vint1.add(arr[0]);
		vint1.add(arr[5]);
		vint1.add(arr[9]);
		vint1.add(arr[11]);
		vint1.add(arr[1]);
		vint1.add(arr[13]);
		iterator<Integer> it1 = vint1.iterator(); 
		vint2.add(arr[0]);
		vint2.add(arr[12]);
		vint2.add(arr[8]);
		vint2.add(arr[5]);
		vint2.add(arr[6]);
		vint2.add(arr[6]);
		iterator<Integer> it2 = vint2.iterator();
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  HashSet Integer test begin  //////////////\n");
		
		System.out.printf("the initial value of the first HashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\nthe initial value of the second HashSet >>");
		while(it2.hasNext()){
			System.out.printf("%s ,",it2.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first HashSet %d\nthe size of the second HashSet %d \n",vint1.size(),vint2.size());
		System.out.printf("adding element to the first HashSet :: %s\n",vint1.add(arr[15]));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first HashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second HashSet to first HashSet :: %s\n",vint1.addAll(vint2));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first HashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the HashSet contain the number 1 :: %s\n",vint1.contains(1));
		System.out.printf("the HashSet contain the second HashSet :: %s\n",vint1.containsAll(vint2));
		System.out.printf("removing the second array from first array\n");
		vint1.removeAll(vint2);
		it1 = vint1.iterator();
		System.out.printf("the new value of the first HashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the HashSet !!!!!!\n");
		vint1.clear();
		System.out.printf("is empty :: %s\n",vint1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  HashSet Integer test end  //////////////\n\n");
			
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  HashSet String test begin  //////////////\n");
		HashSet<String> vstr1 = new HashSet<String>();
		HashSet<String> vstr2 = new HashSet<String>();
		vstr1.add(str[0]);vstr1.add(str[1]);vstr1.add(str[2]);vstr1.add(str[3]);vstr1.add(str[4]);vstr1.add(str[5]);
		vstr1.add(str[6]);vstr1.add(str[7]);vstr1.add(str[8]);vstr1.add(str[9]);
		vstr2.add(str[2]);vstr2.add(str[0]);vstr2.add(str[0]);vstr2.add(str[12]);
		iterator<String> it3 = vstr1.iterator();
		iterator<String> it4 = vstr2.iterator();
		System.out.printf("the initial value of the first HashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\nthe initial value of the second HashSet >>");
		while(it4.hasNext()){
			System.out.printf("%s ,",it4.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first HashSet %d\nthe size of the second HashSet %d \n",vstr1.size(),vstr2.size());
		System.out.printf("adding element to the first HashSet :: %s\n",vstr1.add(str[1]));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first HashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second HashSet to first HashSet :: %s\n",vstr1.addAll(vstr2));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first HashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the HashSet contain (go) :: %s\n",vstr1.contains("go"));
		System.out.printf("the HashSet contain the second HashSet :: %s\n",vstr1.containsAll(vstr2));
		System.out.printf("removing the second array from first array\n");
		vstr1.removeAll(vstr2);
		it3 = vstr1.iterator();
		System.out.printf("the new value of the first HashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the HashSet !!!!!!\n");
		vstr1.clear();
		System.out.printf("is empty :: %s\n",vstr1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  HashSet String test end  //////////////\n");

	}

	public static void LinkedHashSet_tester(){
		String[] str = {"jwan","hussein","gtu","CSE241","vise","final","class","java","class","quiz","test","final","hw8"};
		Integer[] arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,2,3,5,8,9};
		LinkedHashSet<Integer> vint1 = new LinkedHashSet<Integer>();
		LinkedHashSet<Integer> vint2 = new LinkedHashSet<Integer>();		
		vint1.add(arr[7]);
		vint1.add(arr[2]);
		vint1.add(arr[6]);
		vint1.add(arr[5]);
		vint1.add(arr[9]);
		vint1.add(arr[11]);
		vint1.add(arr[1]);
		vint1.add(arr[13]);
		iterator<Integer> it1 = vint1.iterator(); 
		vint2.add(arr[1]);
		vint2.add(arr[12]);
		vint2.add(arr[8]);
		vint2.add(arr[5]);
		vint2.add(arr[6]);
		vint2.add(arr[6]);
		iterator<Integer> it2 = vint2.iterator();
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedHashSet Integer test begin  //////////////\n");
		
		System.out.printf("the initial value of the first LinkedHashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\nthe initial value of the second LinkedHashSet >>");
		while(it2.hasNext()){
			System.out.printf("%s ,",it2.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first LinkedHashSet %d\nthe size of the second LinkedHashSet %d \n",vint1.size(),vint2.size());
		System.out.printf("adding element to the first LinkedHashSet :: %s\n",vint1.add(arr[15]));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first LinkedHashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second LinkedHashSet to first LinkedHashSet :: %s\n",vint1.addAll(vint2));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first LinkedHashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the LinkedHashSet contain the number 1 :: %s\n",vint1.contains(1));
		System.out.printf("the LinkedHashSet contain the second LinkedHashSet :: %s\n",vint1.containsAll(vint2));
		System.out.printf("removing the second array from first array\n");
		vint1.removeAll(vint2);
		it1 = vint1.iterator();
		System.out.printf("the new value of the first LinkedHashSet >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the LinkedHashSet !!!!!!\n");
		vint1.clear();
		System.out.printf("is empty :: %s\n",vint1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedHashSet Integer test end  //////////////\n\n");
			
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedHashSet String test begin  //////////////\n");
		LinkedHashSet<String> vstr1 = new LinkedHashSet<String>();
		LinkedHashSet<String> vstr2 = new LinkedHashSet<String>();
		vstr1.add(str[0]);vstr1.add(str[12]);vstr1.add(str[12]);vstr1.add(str[3]);vstr1.add(str[4]);vstr1.add(str[5]);
		vstr1.add(str[6]);vstr1.add(str[7]);vstr1.add(str[8]);vstr1.add(str[9]);
		vstr2.add(str[2]);vstr2.add(str[0]);vstr2.add(str[0]);vstr2.add(str[12]);
		iterator<String> it3 = vstr1.iterator();
		iterator<String> it4 = vstr2.iterator();
		System.out.printf("the initial value of the first LinkedHashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\nthe initial value of the second LinkedHashSet >>");
		while(it4.hasNext()){
			System.out.printf("%s ,",it4.next());
		}
		System.out.printf("\n");
		System.out.printf("\nthe size of the first LinkedHashSet %d\nthe size of the second LinkedHashSet %d \n",vstr1.size(),vstr2.size());
		System.out.printf("adding element to the first LinkedHashSet :: %s\n",vstr1.add(str[1]));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first LinkedHashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second LinkedHashSet to first LinkedHashSet :: %s\n",vstr1.addAll(vstr2));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first LinkedHashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the LinkedHashSet contain (go) :: %s\n",vstr1.contains("go"));
		System.out.printf("the LinkedHashSet contain the second LinkedHashSet :: %s\n",vstr1.containsAll(vstr2));
		System.out.printf("removing the second array from first array\n");
		vstr1.removeAll(vstr2);
		it3 = vstr1.iterator();
		System.out.printf("the new value of the first LinkedHashSet >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the LinkedHashSet !!!!!!\n");
		vstr1.clear();
		System.out.printf("is empty :: %s\n",vstr1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedHashSet String test end  //////////////\n");

	}
	public static void PriorityQueue_tester(){
		String[] str = {"jwan","hussein","gtu","CSE241","vise","final","class","java","class","quiz","test","final","hw8"};
		Integer[] arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,2,3,5,8,9};
		PriorityQueue<Integer> vint1 = new PriorityQueue<Integer>();
		PriorityQueue<Integer> vint2 = new PriorityQueue<Integer>();		
		vint1.add(arr[7]);
		vint1.add(arr[2]);
		vint1.add(arr[6]);
		vint1.add(arr[5]);
		vint1.add(arr[9]);
		vint1.add(arr[11]);
		vint1.add(arr[1]);
		vint1.add(arr[13]);
		iterator<Integer> it1 = vint1.iterator(); 
		vint2.add(arr[1]);
		vint2.add(arr[12]);
		vint2.add(arr[8]);
		vint2.add(arr[5]);
		vint2.add(arr[6]);
		vint2.add(arr[6]);
		iterator<Integer> it2 = vint2.iterator();
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  PriorityQueue Integer test begin  //////////////\n");
		
		System.out.printf("the initial value of the first PriorityQueue >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\nthe initial value of the second PriorityQueue >>");
		while(it2.hasNext()){
			System.out.printf("%s ,",it2.next());
		}
		System.out.printf("\n");
		System.out.printf("\nPriorityQueue element :: %s \n",vint1.element());
		System.out.printf("PriorityQueue offer :: %s \n",vint1.poll());		
		System.out.printf("\nthe size of the first PriorityQueue %d\nthe size of the second PriorityQueue %d \n",vint1.size(),vint2.size());
		System.out.printf("adding element to the first PriorityQueue :: %s\n",vint1.add(arr[15]));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first PriorityQueue >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second PriorityQueue to first PriorityQueue :: %s\n",vint1.addAll(vint2));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first PriorityQueue >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the PriorityQueue contain the number 1 :: %s\n",vint1.contains(1));
		System.out.printf("the PriorityQueue contain the second PriorityQueue :: %s\n",vint1.containsAll(vint2));
		System.out.printf("removing the second array from first array\n");
		vint1.removeAll(vint2);
		it1 = vint1.iterator();
		System.out.printf("the new value of the first PriorityQueue >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the PriorityQueue !!!!!!\n");
		vint1.clear();
		System.out.printf("is empty :: %s\n",vint1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  PriorityQueue Integer test end  //////////////\n\n");
			
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  PriorityQueue String test begin  //////////////\n");
		PriorityQueue<String> vstr1 = new PriorityQueue<String>();
		PriorityQueue<String> vstr2 = new PriorityQueue<String>();
		vstr1.add(str[0]);vstr1.add(str[12]);vstr1.add(str[12]);vstr1.add(str[3]);vstr1.add(str[4]);vstr1.add(str[5]);
		vstr1.add(str[6]);vstr1.add(str[7]);vstr1.add(str[8]);vstr1.add(str[9]);
		vstr2.add(str[2]);vstr2.add(str[0]);vstr2.add(str[0]);vstr2.add(str[12]);
		iterator<String> it3 = vstr1.iterator();
		iterator<String> it4 = vstr2.iterator();
		System.out.printf("the initial value of the first PriorityQueue >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\nthe initial value of the second PriorityQueue >>");
		while(it4.hasNext()){
			System.out.printf("%s ,",it4.next());
		}
		System.out.printf("\n");
		System.out.printf("\nPriorityQueue element :: %s \n",vstr1.element());
		System.out.printf("PriorityQueue offer :: %s \n",vstr1.poll());	
		System.out.printf("\nthe size of the first PriorityQueue %d\nthe size of the second PriorityQueue %d \n",vstr1.size(),vstr2.size());
		System.out.printf("adding element to the first PriorityQueue :: %s\n",vstr1.add(str[1]));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first PriorityQueue >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second PriorityQueue to first PriorityQueue :: %s\n",vstr1.addAll(vstr2));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first PriorityQueue >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the PriorityQueue contain (go) :: %s\n",vstr1.contains("go"));
		System.out.printf("the PriorityQueue contain the second PriorityQueue :: %s\n",vstr1.containsAll(vstr2));
		System.out.printf("removing the second array from first array\n");
		vstr1.removeAll(vstr2);
		it3 = vstr1.iterator();
		System.out.printf("the new value of the first PriorityQueue >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the PriorityQueue !!!!!!\n");
		vstr1.clear();
		System.out.printf("is empty :: %s\n",vstr1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  PriorityQueue String test end  //////////////\n");

	}
	public static void LinkedList_tester(){
		String[] str = {"jwan","hussein","gtu","CSE241","vise","final","class","java","class","quiz","test","final","hw8"};
		Integer[] arr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,2,3,5,8,9};
		LinkedList<Integer> vint1 = new LinkedList<Integer>();
		LinkedList<Integer> vint2 = new LinkedList<Integer>();		
		vint1.add(arr[7]);
		vint1.add(arr[2]);
		vint1.add(arr[6]);
		vint1.add(arr[5]);
		vint1.add(arr[9]);
		vint1.add(arr[11]);
		vint1.add(arr[1]);
		vint1.add(arr[13]);
		iterator<Integer> it1 = vint1.iterator(); 
		vint2.add(arr[1]);
		vint2.add(arr[12]);
		vint2.add(arr[8]);
		vint2.add(arr[5]);
		vint2.add(arr[6]);
		vint2.add(arr[6]);
		iterator<Integer> it2 = vint2.iterator();
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedList Integer test begin  //////////////\n");
		
		System.out.printf("the initial value of the first LinkedList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\nthe initial value of the second LinkedList >>");
		while(it2.hasNext()){
			System.out.printf("%s ,",it2.next());
		}
		System.out.printf("\n");
		System.out.printf("\nPriorityQueue element :: %s \n",vint1.element());
		System.out.printf("LinkedList offer :: %s \n",vint1.poll());
		System.out.printf("LinkedList indexof (2) :: %s \n",vint1.indexOf(2));		
		System.out.printf("\nthe size of the first LinkedList %d\nthe size of the second LinkedList %d \n",vint1.size(),vint2.size());
		System.out.printf("adding element to the first LinkedList :: %s\n",vint1.add(arr[15]));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first LinkedList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second LinkedList to first LinkedList :: %s\n",vint1.addAll(vint2));
		it1 = vint1.iterator(); 
		System.out.printf("the new value of the first LinkedList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the LinkedList contain the number 1 :: %s\n",vint1.contains(1));
		System.out.printf("the LinkedList contain the second LinkedList :: %s\n",vint1.containsAll(vint2));
		System.out.printf("removing the second array from first array\n");
		vint1.removeAll(vint2);
		it1 = vint1.iterator();
		System.out.printf("the new value of the first LinkedList >>");
		while(it1.hasNext()){
			System.out.printf("%s ,",it1.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the LinkedList !!!!!!\n");
		vint1.clear();
		System.out.printf("is empty :: %s\n",vint1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedList Integer test end  //////////////\n\n");
			
		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedList String test begin  //////////////\n");
		LinkedList<String> vstr1 = new LinkedList<String>();
		LinkedList<String> vstr2 = new LinkedList<String>();
		vstr1.add(str[0]);vstr1.add(str[12]);vstr1.add(str[12]);vstr1.add(str[3]);vstr1.add(str[4]);vstr1.add(str[5]);
		vstr1.add(str[6]);vstr1.add(str[7]);vstr1.add(str[8]);vstr1.add(str[9]);
		vstr2.add(str[2]);vstr2.add(str[0]);vstr2.add(str[0]);vstr2.add(str[12]);
		iterator<String> it3 = vstr1.iterator();
		iterator<String> it4 = vstr2.iterator();
		System.out.printf("the initial value of the first LinkedList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\nthe initial value of the second LinkedList >>");
		while(it4.hasNext()){
			System.out.printf("%s ,",it4.next());
		}
		System.out.printf("\n");
		System.out.printf("\nPriorityQueue element :: %s \n",vstr1.element());
		System.out.printf("LinkedList offer :: %s \n",vstr1.poll());
		System.out.printf("LinkedList indexof (gtu) :: %s \n",vint1.indexOf("gtu"));			
		System.out.printf("\nthe size of the first LinkedList %d\nthe size of the second LinkedList %d \n",vstr1.size(),vstr2.size());
		System.out.printf("adding element to the first LinkedList :: %s\n",vstr1.add(str[1]));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first LinkedList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("adding all element of second LinkedList to first LinkedList :: %s\n",vstr1.addAll(vstr2));
		it3 = vstr1.iterator(); 
		System.out.printf("the new value of the first LinkedList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("\n");
		System.out.printf("the LinkedList contain (go) :: %s\n",vstr1.contains("go"));
		System.out.printf("the LinkedList contain the second LinkedList :: %s\n",vstr1.containsAll(vstr2));
		System.out.printf("removing the second array from first array\n");
		vstr1.removeAll(vstr2);
		it3 = vstr1.iterator();
		System.out.printf("the new value of the first LinkedList >>");
		while(it3.hasNext()){
			System.out.printf("%s ,",it3.next());
		}
		System.out.printf("\n");
		System.out.printf("clear the LinkedList !!!!!!\n");
		vstr1.clear();
		System.out.printf("is empty :: %s\n",vstr1.isEmpty());
		
		

		System.out.printf("\n \\\\\\\\\\\\\\\\\\\\\\\\  LinkedList String test end  //////////////\n");

	}
}