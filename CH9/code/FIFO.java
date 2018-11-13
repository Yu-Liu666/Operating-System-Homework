package os;

/**
 * This class implements the FIFO page-replacement strategy.
 *
 */

public class FIFO extends ReplacementAlgorithm
{
	// FIFO list of page frames
	private FIFOList frameList;

	/**
	 * @param pageFrameCount - the number of physical page frames
	 */
	public FIFO(int pageFrameCount) {
		super(pageFrameCount);
		frameList = new FIFOList(pageFrameCount);
	}


	/**
	 * insert a page into a page frame.
	 * @param int pageNumber - the page number being inserted.
	 */
	public void insert(int pageNumber) {
	     
		frameList.insert(pageNumber);
		
    }
		
	class FIFOList
	{
		// the page frame list
		int[] pageFrameList;

		// the number of elements in the page frame list
		int elementCount;

		FIFOList(int pageFrameCount) {
			pageFrameList = new int[pageFrameCount];

            // we initialize each entry to -1 to indicate initial value is invalid 
            java.util.Arrays.fill(pageFrameList,-1);
			elementCount = 0;
		}

		/**
		 * @param pageNumber the number of the page to be 
		 *	inserted into the page frame list.
		 */
		void insert(int pageNumber) {
	
boolean b=search(pageNumber);
			
			if(b)
			{
				
			System.out.println("发出请求的并且已经有的"+pageNumber+"不做调整");	
			dump();
			System.out.println();
			   
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

		// dump the page frames
		void dump() {
			for (int i = 0; i < pageFrameList.length; i++)
				System.out.print("["+i+"]"+pageFrameList[i]+", ");
		}


		/**
		 * Searches for page pageNumber in the page frame list
		 * @return true if pageNumber was found
		 * @return false if pageNumber was not found
		 */
		boolean search(int pageNumber) {
			boolean returnVal = false;

			for (int i = 0; i < pageFrameList.length; i++) {
				if (pageNumber == pageFrameList[i]) {
					returnVal = true;
					break;
				}
			}
			return returnVal;
		}
	}
}
