/**
 * 주식데이터에서 삼성전자 주식(종목단축코드A005930)만 추출해서 새로운 csv만들기
 */
package chap8;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Practice02 {

	public static void main(String[] args) throws IOException{
		// 프로그램 시작 시점의 시간(밀리초 리턴이기에 몇초인지 알려면 1000으로 나눠주기)
		int k38_beginTime = (int)(System.currentTimeMillis() / 1000);
		
		File k38_f = new File("D:\\\\JAEUG\\\\자바 8장 파일 실습\\\\주식데이터\\\\day_data\\\\StockDailyPrice_final.csv"); // 파일 오픈
		BufferedReader k38_br = new BufferedReader(new FileReader(k38_f)); // 파일 읽기 준비
		
		File k38_f1 = new File("D:\\JAEUG\\자바 8장 파일 실습\\주식데이터\\day_data\\A005930_2.csv");
		BufferedWriter k38_bw1 = new BufferedWriter(new FileWriter(k38_f1)); // 파일에 쓰기 준비
		
		String k38_readtxt; // 읽기용 스트링
		// 몇줄 읽었는지 // 몇줄 써넣었는지
		int k38_cnt = 0; int k38_wcnt = 0;
		while ((k38_readtxt = k38_br.readLine()) != null) { // 파일 시작부터 끝까지 한줄씩 읽기
			StringBuffer k38_s = new StringBuffer(); // 스트링 값 수정에 용이한 스트링버퍼이용
			String[] k38_field = k38_readtxt.split(","); // 구분자(콤마) 기준으로 분할하여 배열에 데이터 입력
			String[] k38_samjun_field = new String[k38_field.length]; // 삼성전자 주식 데이터만 담을 배열
			// 삼성전자(단축종목코드 A005930)만 추출해서 새로운 배열 생성
			if (k38_field[2].equals("A005930")) {
				for (int k38_i=0; k38_i<k38_field.length; k38_i++) {
					 k38_samjun_field[k38_i] = k38_field[k38_i]; // 새로 만든 배열에다가 전체증권데이터중에서 위에 명시한 조건에 맞는 녀석들만 데이터로 입력
				}//
				
				// 새로운 데이터를 csv형식으로 변환
				k38_s.append(k38_samjun_field[0]); // 가장 첫번째 칼럼은 값만 입력하고
				for (int k38_i=1; k38_i<k38_samjun_field.length; k38_i++) {
					k38_s.append(",").append(k38_samjun_field[k38_i]); // 두번째 칼럼 부터는 값 앞에 ,를 먼저 넣고 값을 넣어줌
				}//
				
				k38_bw1.write(k38_s.toString()); k38_bw1.newLine(); // 구성된 스트링버퍼를 이용해 파일에 내용 써넣기
				k38_wcnt++; // 몇줄 써넣었는지 카운트
			}// if
			
			k38_cnt++; // 한줄 읽는게 끝날때마다 카운트(몇줄을 읽었는지 세기)
		}// while
		k38_br.close(); // 파일 닫아주기!
		k38_bw1.close(); // 파일 닫아주기!
		
		System.out.printf("Program End[%d][%d]records\n", k38_cnt, k38_wcnt); // 총 몇줄을 읽었고 몇줄을 적었는지 프린트
		// 프로그램 종료 시점의 시간(밀리초 리턴이기에 몇초인지 알려면 1000으로 나눠주기)
		int k38_endTime = (int)(System.currentTimeMillis() / 1000);
		System.out.printf("※ 프로그램이 실행되는데 걸린 시간은: [%d초]입니다", k38_endTime-k38_beginTime);
	
	}// main

}// class
