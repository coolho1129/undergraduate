package monday;
public class moveThread implements Runnable {
	AutoTextShift callback;
	public moveThread(AutoTextShift obj) {
		
		this.callback=obj;
	}
	
	public void run() {
		
		for(;;) {
			
			callback.move();
		
		}
	}

}
