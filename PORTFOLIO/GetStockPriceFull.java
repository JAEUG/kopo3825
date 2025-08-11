import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class GetStockPriceFull {

	public static void main(String[] args) {
		int k38_startTime = (int)(System.currentTimeMillis() / 1000);
		
		Connection k38_conn = null;
		Statement k38_stmt = null;
		PreparedStatement k38_pstmt = null;
		PreparedStatement k38_pstmt2 = null;
		ResultSet k38_rset = null;
		ResultSet k38_rset2 = null;
		String k38_dbUrl = "jdbc:mysql://192.168.23.229:3306/kopoctc?rewriteBatchedStatements=true";
		String k38_driverUrl = "com.mysql.cj.jdbc.Driver";
		try {
			Class.forName(k38_driverUrl);
			k38_conn = DriverManager.getConnection(k38_dbUrl, "root", "kopo38!");
			String k38_queryTxt = "select * from stock_price_full where shrn_iscd = ?"; // 삼성전자 조회 쿼리
			String k38_queryTxt2 = "select DATA_TYPE from information_schema.columns where table_name = 'stock_price_full' order by ordinal_position asc"; // stock_price_full 컬럼 데이터타입 조회
			String k38_queryTxt3 = "select * from stock_price_full where bsop_date = ?"; // 특정일자 조회 쿼리
			k38_stmt = k38_conn.createStatement();
			
			k38_pstmt = k38_conn.prepareStatement(k38_queryTxt); // 삼성
			k38_pstmt.setString(1, "A005930");
			
			k38_pstmt2 = k38_conn.prepareStatement(k38_queryTxt3); // 특정 일자
			k38_pstmt2.setString(1, "2016-04-15");
			
			k38_rset2 = k38_stmt.executeQuery(k38_queryTxt2);
			k38_rset = k38_pstmt.executeQuery();  // 번갈아 가며 실행
//			k38_rset = k38_pstmt2.executeQuery(); // 번갈아 가며 실행
			
			List<String> k38_typeArrayList = new ArrayList<>();
			while (k38_rset2.next()) {
				k38_typeArrayList.add(k38_rset2.getString(1)); // ArrayList에 각 컬럼의 자료형을 차례로 담아준다
			}
			
			for (int i = 0; i < k38_typeArrayList.size(); i++) { // ArrayList의 크기만큼(컬럼의 갯수만큼)
				if (k38_typeArrayList.get(i).equals("varchar")) { // sql에서 varchar -> java에서 String
					k38_typeArrayList.set(i, "String");
				} else if (k38_typeArrayList.get(i).equals("mediumtext")) { // sql에서 mediumtext -> java에서 String
					k38_typeArrayList.set(i, "String");
				} else if (k38_typeArrayList.get(i).equals("bigint")) { // sql에서 bigint -> java에서 long
					k38_typeArrayList.set(i, "long");
				} else if (k38_typeArrayList.get(i).equals("date")) { // sql에서 date -> java에서 String
					k38_typeArrayList.set(i, "String");
				}
			}
			int k38_dataCnt = 1;
			
			// 필드 이름 99개 출력하려면 다 담아줘야겠지? ㅋㅋ
	        List<String> k38_fieldNameList = new ArrayList<>();
	        k38_fieldNameList.add("표준 종목코드"); k38_fieldNameList.add("주식 영업 일자"); k38_fieldNameList.add("단축 종목코드");
	        k38_fieldNameList.add("주식 종가"); k38_fieldNameList.add("주식 시가"); k38_fieldNameList.add("주식 최고가");
	        k38_fieldNameList.add("주식 최저가"); k38_fieldNameList.add("전일 대비 부호"); k38_fieldNameList.add("전일 대비");
	        k38_fieldNameList.add("전일 대비율"); k38_fieldNameList.add("전일 거래량"); k38_fieldNameList.add("누적 거래량");
	        k38_fieldNameList.add("누적 거래 대금"); k38_fieldNameList.add("매도호가1"); k38_fieldNameList.add("매수호가1");
	        k38_fieldNameList.add("총 매도호가 잔량"); k38_fieldNameList.add("총 매수호가 잔량"); k38_fieldNameList.add("매도 체결 합계");
	        k38_fieldNameList.add("매수 체결 합계"); k38_fieldNameList.add("매도 거래 대금(누적)"); k38_fieldNameList.add("매수 거래 대금(누적)");
	        k38_fieldNameList.add("매도 체결 건수"); k38_fieldNameList.add("매수 체결 건수"); k38_fieldNameList.add("52주일 최고가");
	        k38_fieldNameList.add("52주일 최저가"); k38_fieldNameList.add("52주일 최고가 일자"); k38_fieldNameList.add("52주일 최저가 일자");
	        k38_fieldNameList.add("시간외 단일가 최종 시간"); k38_fieldNameList.add("시간외 단일가 현재가"); k38_fieldNameList.add("시간외 단일가 전일 대비");
	        k38_fieldNameList.add("시간외 단일가 전일 대비 부호"); k38_fieldNameList.add("시간외 단일가 매도호가1"); k38_fieldNameList.add("시간외 단일가 매수호가1");
	        k38_fieldNameList.add("시간외 단일가 거래량"); k38_fieldNameList.add("시간외 단일가 거래 대금"); k38_fieldNameList.add("시간외 단일가 시가");
	        k38_fieldNameList.add("시간외 단일가 최고가"); k38_fieldNameList.add("시간외 단일가 최저가"); k38_fieldNameList.add("장개시전 시간외종가 거래량");
	        k38_fieldNameList.add("장개시전 시간외종가 거래 대금"); k38_fieldNameList.add("장종료후 시간외종가 거래량"); k38_fieldNameList.add("장종료후 시간외종가 거래 대금");
	        k38_fieldNameList.add("시장 분류 구분 코드"); k38_fieldNameList.add("주당 배당 금액"); k38_fieldNameList.add("상장 주수");
	        k38_fieldNameList.add("주식 기준가"); k38_fieldNameList.add("주식 액면가"); k38_fieldNameList.add("가중 평균 주식 가격");
	        k38_fieldNameList.add("종목 한도 비율"); k38_fieldNameList.add("외국인 한도 수량"); k38_fieldNameList.add("주문 가능 수량");
	        k38_fieldNameList.add("외국인 한도 소진 구분 코드"); k38_fieldNameList.add("외국인 보유 수량"); k38_fieldNameList.add("외국인 보유 비율");
	        k38_fieldNameList.add("HTS 외국인 소진율"); k38_fieldNameList.add("장중 최종 NAV"); k38_fieldNameList.add("전일 최종 NAV");
	        k38_fieldNameList.add("추적 오차율"); k38_fieldNameList.add("괴리율"); k38_fieldNameList.add("공매도차입증권매도체결수량");
	        k38_fieldNameList.add("공매도차입증권매도거래대금"); k38_fieldNameList.add("외국인 순매수"); k38_fieldNameList.add("락구분 코드");
	        k38_fieldNameList.add("분할 비율"); k38_fieldNameList.add("누적 분할 비율"); k38_fieldNameList.add("전체융자잔고비율");
	        k38_fieldNameList.add("베타 계수(90일)"); k38_fieldNameList.add("DEL 상관 계수"); k38_fieldNameList.add("DEL 강세 계수");
	        k38_fieldNameList.add("DEL 약세 계수"); k38_fieldNameList.add("DEL 강세 편차"); k38_fieldNameList.add("DEL 약세 편차");
	        k38_fieldNameList.add("DEL 강세 상관계수"); k38_fieldNameList.add("DEL 약세 상관계수"); k38_fieldNameList.add("주식 상한가");
	        k38_fieldNameList.add("주식 하한가"); k38_fieldNameList.add("증자 구분 코드"); k38_fieldNameList.add("장중 거래량");
	        k38_fieldNameList.add("장중 거래대금"); k38_fieldNameList.add("액면가 변경 구분 코드"); k38_fieldNameList.add("재평가 종목 사유 코드");
	        k38_fieldNameList.add("기관계 순매수"); k38_fieldNameList.add("수정주가 (교보:fnguide때문에 추가)"); k38_fieldNameList.add("주식 시가");
	        k38_fieldNameList.add("주식 최고가"); k38_fieldNameList.add("주식 최저가"); k38_fieldNameList.add("주식 종가");
	        k38_fieldNameList.add("누적 거래량"); k38_fieldNameList.add("누적 거래 대금"); k38_fieldNameList.add("분할 비율");
	        k38_fieldNameList.add("락구분 코드"); k38_fieldNameList.add("Buy-in 일반 체결가"); k38_fieldNameList.add("Buy-in 일반 종가 대비");
	        k38_fieldNameList.add("Buy-in 일반 체결량"); k38_fieldNameList.add("Buy-in 일반 체결 대금"); k38_fieldNameList.add("Buy-in 당일 체결가");
	        k38_fieldNameList.add("Buy-in 당일 종가 대비"); k38_fieldNameList.add("Buy-in 당일 체결량"); k38_fieldNameList.add("Buy-in 당일 체결 대금");
			
			while (k38_rset.next()) {
				
				System.out.printf("( %d )********************************************\n", k38_dataCnt++);
				// String, int, float, long
				for (int i = 0; i < k38_typeArrayList.size(); i++) { // 필드 순서에 맞게 필드이름과 필드값을 설정하여 출력한다
					if (k38_typeArrayList.get(i).equals("String")) {
						String k38_stringData = k38_rset.getString(i + 1);
						System.out.printf("%s : %s\n", k38_fieldNameList.get(i), k38_stringData);
					} else if (k38_typeArrayList.get(i).equals("int")) {
						int k38_intData = k38_rset.getInt(i + 1);
						System.out.printf("%s : %d\n", k38_fieldNameList.get(i), k38_intData);
					} else if (k38_typeArrayList.get(i).equals("float")) {
						float k38_floatData = k38_rset.getFloat(i + 1);
						System.out.printf("%s : %.2f\n", k38_fieldNameList.get(i), k38_floatData);
					} else if (k38_typeArrayList.get(i).equals("long")) {
						long k38_longData = k38_rset.getLong(i + 1);
						System.out.printf("%s : %d\n", k38_fieldNameList.get(i), k38_longData);
					}
				}// for
				System.out.printf("************************************************\n");
			}// while
			System.out.printf("조회된 데이터 총 [%d]건\n", k38_dataCnt - 1);
		} catch(SQLException e) {
			System.out.println("SQL 오류 발생 " + e.getMessage());
			System.out.println("SQL 오류 코드: " + e.getErrorCode());
		} catch(ClassNotFoundException e) {
			System.out.println("Driver 객체 생성 실패");
		} finally {
				try {
					if (k38_conn != null) k38_conn.close();
					if (k38_stmt != null) k38_stmt.close();
					if (k38_pstmt != null) k38_pstmt.close();
					if (k38_pstmt2 != null) k38_pstmt2.close();
					if (k38_rset != null) k38_rset.close();
					if (k38_rset2 != null) k38_rset2.close();
				} catch (SQLException e) {
					System.out.println("DB 연결 해제 오류");
					e.printStackTrace();
				}
		}
		int k38_endTime = (int)(System.currentTimeMillis() / 1000);
		System.out.println("System 실행 종료");
		System.out.printf("시스템 실행 소요 시간: [%d초]", k38_endTime - k38_startTime);
	}// main

}// class
