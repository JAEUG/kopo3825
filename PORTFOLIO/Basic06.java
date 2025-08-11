package chap8;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Basic06 {

	public static void main(String[] args) throws IOException{
		// 프로그램 시작 시점의 시간(밀리초 리턴이기에 몇초인지 알려면 1000으로 나눠주기)
		int k38_beginTime = (int)(System.currentTimeMillis() / 1000);
		
		File k38_f = new File("D:\\JAEUG\\자바 8장 파일 실습\\주식데이터\\day_data\\THTSKS010H00.dat"); // 파일 오픈
		BufferedReader k38_br = new BufferedReader(new FileReader(k38_f)); // 파일 읽기 준비
		
		File k38_f1 = new File("D:\\JAEUG\\자바 8장 파일 실습\\주식데이터\\day_data\\StockDailyPrice_final2.csv");
		BufferedWriter k38_bw1 = new BufferedWriter(new FileWriter(k38_f1)); // 파일에 쓰기 준비
		
		String k38_readtxt; // 읽기용 스트링
		// 몇줄 읽었는지 // 몇줄 써넣었는지
		int k38_cnt = 0; int k38_wcnt = 0;
		while ((k38_readtxt = k38_br.readLine()) != null) { // 파일 시작부터 끝까지 한줄씩 읽기
			StringBuffer k38_s = new StringBuffer(); // 스트링 값 수정에 용이한 스트링버퍼이용
			/////////////////////////////////////////////////////
			/// String 정제 부분
			///////////////////////////
			// 앞에서 이 파일의 내용을 50줄 살펴본 결과 구분자(seperator)가 ^%_%^로 되어있는 파일로 보였다
			// 그래서 ^%_%^으로 split을 시도하였는데 실패하셨다. 구분자를 %_%로 하고
			// ^는 모두 삭제시켜버리기로 하였다. 그리고 여러 데이터중에 주식 데이터(종목 단축코드 앞이 A인것들)만 
			// 추출하고 데이터 사이마다 콤마를 삽입하여 csv로 새로운 파일을 만들기로 하였다. 아래는 구현 과정이다
			String[] k38_field = k38_readtxt.split("%_%"); // 일단 %_%기준으로 잘라준다 
			// field의 크기가 2보다 크고(스트럭처를 보니 종목단축코드가 3번째 칼럼에 위치하기에)
			// 2번 인덱스 즉 3번째 칼럼의 값(단축종목코드)를 가져다가 포함된 ^를 삭제시키고, 공백을 제거한 후에 맨 앞글자를 보았더니 "A"라면(주식인거지 빙고!)
			if (k38_field.length>2 && k38_field[2].replace("^", "").trim().substring(0, 1).equals("A")) {
				// 스트링버퍼 구축 시작... 일단 첫번째 칼럼(표준종목코드)을 가져다 ^을 삭제하고 공백을 지운다음
				// k38_s에 넣어준다
				k38_s.append(k38_field[0].replace("^", "").trim());  
				for (int k38_j=1; k38_j < k38_field.length; k38_j++) { // 그 다음, 2번 칼럼부터 마지막 칼럼까지(j값이 1인것에 주의!)
					k38_s.append("," + k38_field[k38_j].replace("^", "").trim()); // 앞에 ,를 넣고 각 값들은 ^와 공백을 제거하고 넣어준다!
				}// for
				k38_bw1.write(k38_s.toString()); k38_bw1.newLine(); // 완성된 스트링버퍼를 스트링으로 변환하여 파일에 입력해준다 한줄 입력 끝나면 한줄 띄우기
				k38_wcnt++; // 한 줄 입력 끝날때마다 카운트(몇줄을 입력했는지 세기)
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
