package hw1;

//학번: 2021114818
//이름: 김찬호
import java.util.Scanner;

public class LottoGeneration {

	static boolean isDuplicate(int arry[], int N, int r) {
		for (int i = 0; i < N; i++) {
			if (arry[i] == r) {
				return true;
			}

		}
		return false;
	}

	static void PrintLottonum(int arry[]) {

		for (int i = 0; i < 6; i++)
			System.out.printf("%2d ", arry[i]);

	}

	static void ArryInit(int arry[]) {
		for (int i = 0; i < 6; i++)
			arry[i] = 0;

	}

	static void LottoFreq(int Lotto[], int count[]) {
		for (int i = 0; i < Lotto.length; i++) {
			for (int j = 0; j < count.length; j++) {
				if (Lotto[i] == j + 1)
					count[j]++;

			}

		}

	}

	static void PrintLottoFreq(int count[]) {

		for (int i = 0; i < count.length; i++) {
			if (count[i] != 0) {
				System.out.printf("%2d: ", i + 1);
				for (int j = 0; j < count[i]; j++)
					System.out.printf("*");
				System.out.println("");

			}

		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N;
		int Lotto[] = new int[6];
		int count[] = new int[45];
		for (;;) {
			System.out.println("Lotto 수행 횟수를 입력하세요(1~5)");
			N = scanner.nextInt();
			if ((N <= 0) || (N > 5))
				System.out.println("1에서 5사이의 숫자를 다시 입력하세요.");
			else {
				scanner.close();
				break;
			}

		}

		for (int i = 1; i <= N; i++) {
			System.out.print("Lotto [" + i + "]: ");
			for (int j = 0; j < 6; j++) {
				int r = (int) (Math.random() * 45 + 1);

				if (!isDuplicate(Lotto, j, r)) {
					Lotto[j] = r;
				} else
					j--;

			}
			LottoFreq(Lotto, count);
			PrintLottonum(Lotto);
			System.out.println("");
			ArryInit(Lotto);

		}

		System.out.println("Lotto 번호별 빈도수");
		PrintLottoFreq(count);

	}

}
