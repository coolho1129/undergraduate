from pyfiglet import Figlet
from datetime import datetime
import os, time

def main():
    
    f = Figlet(font='big')
    

    def clear_screen(n):
        
        clear = lambda: os.system("cls")
        time.sleep(n)
        clear()
        

    def display_clock():
        
        while True:
            try:
                today = datetime.today()
                clock = today.strftime('%I : %M : %S %p')
                print(f.renderText(clock))
                clear_screen(1)
                
            except KeyboardInterrupt as e:
                print(f"CTRL_C로 중단 되었습니다. {e}")
                break
                
    clear_screen(0)
    display_clock() 
    

if __name__ == "__main__":
    main()

