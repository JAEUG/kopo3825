import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class InsertStockPriceFull {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int startTime = (int)(System.currentTimeMillis() / 1000); // 프로그램 시작 시간
		
		Connection k38_conn = null;
		Statement k38_stmt = null;
		ResultSet k38_rset = null;
		PreparedStatement k38_pstmt = null;
		String dbUrl = "jdbc:mysql://192.168.23.229:3306/kopoctc?rewriteBatchedStatements=true";
		String fileUrl = "D:\\JAEUG\\자바 8장 파일 실습\\주식데이터\\day_data\\StockDailyPrice_final.csv";
		try {
			BufferedReader k38_br = new BufferedReader(new FileReader(fileUrl));
			Class.forName("com.mysql.cj.jdbc.Driver");
			k38_conn = DriverManager.getConnection(dbUrl, "root", "kopo38!");
			k38_conn.setAutoCommit(false); // 오토 커밋 비활성화
			k38_stmt = k38_conn.createStatement();
			k38_pstmt = k38_conn.prepareStatement("insert ignore into stock_price_full values (" // 반드시 while 문 밖에서 pstmt 객체 생성
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
												+ "?, ?, ?, ?, ?, ?, ?, ?, ?)");
			// information_schema 에서 stock_price_full의 컬럼의 자료형을 모두 조회, 순서는 table create할때 지정한 순서로 
			String k38_queryTxt2 = String.format("select DATA_TYPE from information_schema.columns where table_name = '%s' order by ordinal_position asc", "stock_price_full");
			//String k38_queryTxt2 = String.format("select t.type from show column from stock_price_full as t");
			
			k38_rset = k38_stmt.executeQuery(k38_queryTxt2); // 컬럼 자료형 조회 쿼리문 실행
			List<String> k38_typeArrayList = new ArrayList<>();
			while (k38_rset.next()) {
				k38_typeArrayList.add(k38_rset.getString(1)); // ArrayList에 각 컬럼의 자료형을 차례로 담아준다
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
					
			//k38_stmt = k38_conn.createStatement();
			
			String k38_line;
			int k38_dataCnt = 1;
			while ((k38_line = k38_br.readLine()) != null) {
				String[] k38_field = k38_line.split(",");
				
				if (k38_field.length != 99) { // ArrayIndexOutofBounds 오류 방지
					k38_field = Arrays.copyOf(k38_field, 99);
				}
				for (int i = 0; i < k38_field.length; i++) { // Parse 시 NumberFormatException 오류 방지
					if (k38_field[i] == null || k38_field[i].equals("")) {
						k38_field[i] = "0";
					}
				}
				
//				System.out.printf("[주식 영업 일자: %s, 단축 종목 코드: %s, 주식종가: %s, 주식 시가: %s, 주식 최고가: %s, 주식 최저가: %s, 누적 거래량: %s, 누적 거래 대금: %s]\n",
//						k38_field[1], k38_field[2], k38_field[3], k38_field[4], k38_field[5], k38_field[6], k38_field[11], k38_field[12]);
//				String k38_queryTxt = String.format("insert ignore into stock_price values ("
//									+ "'%s', '%s', %s, %s, "
//									+ "%s, %s, %s, %s)",
//									k38_field[1], k38_field[2], k38_field[3], k38_field[4], 
//									k38_field[5], k38_field[6], k38_field[11], k38_field[12]);
				
				for (int i = 0; i < k38_typeArrayList.size(); i++) { // PreparedStatement의 파라미터를 컬럼의 자료형에 맞게 설정
					if (k38_typeArrayList.get(i).equals("String")) {
						k38_pstmt.setString(i + 1, k38_field[i]);
					} else if (k38_typeArrayList.get(i).equals("int")) {
						k38_pstmt.setInt(i + 1, Integer.parseInt(k38_field[i]));
					} else if (k38_typeArrayList.get(i).equals("float")) {
						k38_pstmt.setFloat(i + 1, Float.parseFloat(k38_field[i]));
					} else if (k38_typeArrayList.get(i).equals("double")) {
						k38_pstmt.setDouble(i + 1, Double.parseDouble(k38_field[i]));
					} else if (k38_typeArrayList.get(i).equals("long")) {
						k38_pstmt.setLong(i + 1, Long.parseLong(k38_field[i]));
					}  
				}
				//k38_stmt.execute(k38_queryTxt);
				// k38_stmt.addBatch(k38_queryTxt);
				
				k38_pstmt.addBatch(); // 메모리에 적재
				k38_pstmt.clearParameters(); // pstmt 파라미터 초기화
				
				if (k38_dataCnt % 10000 == 0) { // 1만건당
					k38_pstmt.executeBatch(); // 쿼리 실행
					// System.out.printf("[%d]건 메모리상에 등록 완료\n", k38_dataCnt);
					k38_conn.commit(); // DB에 저장하기
					System.out.printf("[%d]건 DB에 등록 완료\n", k38_dataCnt);
				}
				k38_dataCnt++; // 데이터 수 카운트
			}// while
			
			k38_pstmt.executeBatch();
			// System.out.printf("[%d]건 메모리상에 등록 완료\n", k38_dataCnt);
			k38_conn.commit();
			
			System.out.println("**************************************************************");
			System.out.printf("총 [%d]건의 데이터 stock_price 테이블에 저장 완료\n", k38_dataCnt);
	
		} catch(SQLException e) {
			System.out.println("SQL 오류 발생 " + e.getMessage());
			System.out.println("SQL 오류 코드: " + e.getErrorCode());
		} catch(ClassNotFoundException e) {
			System.out.println("Driver 객체 생성 실패 " + e.getMessage());
		} catch (FileNotFoundException e) {
			System.out.println("파일을 찾을 수 없습니다.");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("파일을 읽는데 실패하였습니다.");
			e.printStackTrace();
		} finally {
			try {
				if (k38_conn != null) k38_conn.close();
				if (k38_stmt != null) k38_stmt.close();
				if (k38_pstmt != null) k38_pstmt.close();
				if (k38_rset != null) k38_rset.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		int endTime = (int)(System.currentTimeMillis() / 1000); // 프로그램 종료 시간
		System.out.printf("프로그램 실행되는데 걸린 시간: [%d]초", endTime - startTime);
	}// main

}// class
