package os;

/**
 * This class implements the LRU page-replacement strategy.
 *
 */

public class LRU extends ReplacementAlgorithm
{
	// LRU list of page frames
	private LRUList frameList;

	/**
	 * @param pageFrameCount - the number of physical page frames
	 */
	public LRU(int pageFrameCount) {
		super(pageFrameCount);
		frameList = new LRUList(pageFrameCount);
	}

	/**
	 * Insert a page into a page frame.
	 */
	public void insert(int pageNumber) {
		frameList.insert(pageNumber);
	
    }
		
	class LRUList
	{
		// the page frame list
		int[] pageFrameList;

		// the number of elements in the page frame list
		int elementCount;

		// the last page inserted
		int lastInserted = -1;

		int number=0;
		LRUList(int pageFrameCount) {
			pageFrameList = new int[pageFrameCount];

            // we initialize each entry to -1 to indicate initial value is invalid.
            java.util.Arrays.fill(pageFrameList,-1);
			elementCount = 0;
		}

		/**
		 * @param pageNumber the number of the page to be 
		 *	inserted into the page frame list.
		 */
		void insert(int pageNumber) {
		int b=search(pageNumber);
			
			if(b!=-1)
			{
				
			System.out.println("发出请求的并且已经有的"+pageNumber);	
			System.out.println("调整之前");
			dump();
			System.out.println();	
			   elementCount--;
		//	   System.out.println("LRU---Find it");
			   for(int i=b;i<elementCount;i++)
				{
					pageFrameList[i]=pageFrameList[i+1];	
				}
			   pageFrameList[elementCount]=pageNumber;
		
			   System.out.println("调整之前");
			   dump();
			   System.out.println();	
			   
			   elementCount++;		   
			}
		
			else{
				pageFaultCount++;
				System.out.println("发出请求的数组里面没有的"+pageNumber);	
				System.out.println("加入之前");
				dump();
				System.out.println();
				int p=elementCount;
				if(p<pageFrameCount)
				{
					
					pageFrameList[elementCount]=pageNumber;
					elementCount++;
					number++;
				}
				else{
					elementCount--;
					for(int i=0;i<pageFrameList.length-1;i++)
					{
						pageFrameList[i]=pageFrameList[i+1];	
					}
				
			
					pageFrameList[elementCount]=pageNumber;
			//		System.out.println(elementCount);
					elementCount++;
				}
				System.out.println("加入之后");
				dump();
				System.out.println();
			}
        }

		void dump() {
			for (int i = 0; i < pageFrameList.length; i++)
				System.out.print("["+i+"]"+pageFrameList[i]+", ");
	//		System.out.print(" element count = " + elementCount);
		}


		/**
		 * Searches for page pageNumber in the page frame list
		 * @return non-negative integer if pageNumber was found
		 * @return -1 if pageNumber was not found
		 */
		int search(int pageNumber) {
			int returnVal = -1;

			for (int i = 0; i < pageFrameList.length; i++) {
				if (pageNumber == pageFrameList[i]) {
					returnVal = i;
					break;
				}
			}
			return returnVal;
		}
	}
}
