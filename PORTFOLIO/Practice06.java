/**
 * 2025-03-13 (목)
 * kopo38 허재욱
 * 영수증 출력하기(e마트)
 */
package chap5;

import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Practice06 {
	/////////////////////
	/// 함수 블록 시작 //
	/////////////////////
	// 특정칸의 넓이가 정해져있을때 그 칸안에 특정 스트링을 가운데 정렬하기 위해 띄워야하는 블랭크 숫자 계산해주는 함수
	public static int k38_calcCenter(String k38_s, int k38_allowed_space) {
		int k38_reqSpace = 0;
		int k38_prtLength = 0;
		
		for (int k38_i = 0; k38_i < k38_s.length(); k38_i++) { // 스트링 길이만큼
			String k38_a = k38_s.substring(k38_i, k38_i+1); // 스트링을 앞에서부터 한글자씩 뽑아오기
			if (k38_a.getBytes().length == 1) { // 뽑아온 글자의 바이트 크기가 1이라면, 영문
				k38_prtLength += 1;
			} else { // 뽑아온 글자의 바이트 크기가 1보다 크다면, 한글 혹은 기타 언어
				k38_prtLength += 2;
			}//
			
		}// for
		System.out.printf("▶▶▶ 입력하신 스트링의 인쇄길이는: %d입니다", k38_prtLength);
		if (k38_prtLength <= k38_allowed_space) {
			k38_reqSpace = k38_prtLength + (k38_allowed_space - k38_prtLength)/2;
			System.out.println("\n▶▶▶ 입력하신 스트링을 가운데 정렬하기 위해서는 " + k38_reqSpace + "칸을 잡으셔야합니다");
		} else {
			System.out.println("\n※※※ 스트링 길이가 너무 길어서 가운데 정렬이 불가능합니다 ※※※");
		}// if
		
		return k38_reqSpace;
	}//
	
	public static String k38_prtChars(String k38_myChar, int k38_charNum) {
		String k38_sChars = "";
		for (int k38_i = 0; k38_i < k38_charNum; k38_i++) {
			k38_sChars = k38_sChars + k38_myChar;
		}//
		return k38_sChars;
	}// k38_prtChars
	
	public static String k38_fblank(String k38_str, int k38_print_len) {
		String k38_ret = "";
		int k38_prtCnt = 0;
		for (int k38_i = 0; k38_i < k38_str.length(); k38_i++) { // String입력을 앞에서부터 한글자씩 검사
			String k38_a = k38_str.substring(k38_i, k38_i+1);
			if (k38_a.getBytes().length == 1) { // 해당 글자가 영문
				// 영문의 경우에는 한글자당 인쇄도 한칸, 인쇄할칸에 한글자가 더 왔을때 원하는 인쇄길이를 넘어선다면 stop!
				if (k38_prtCnt+1 > k38_print_len) break; 
				k38_prtCnt = k38_prtCnt + 1; // 한글자 돌때마다 인쇄 칸 한칸 잡아먹기
				k38_ret = k38_ret + k38_a; // 리턴할 스트링에 해당 문자 더하기
			} else { // 한글등(한글은 1글자당 인쇄칸을 2칸씩 먹는다)
				// 한글의 경우에는 한글자당 인쇄를 두칸, 인쇄할칸에 한글자(k38_prtCnt에 2가 더해짐)가 더 왔을때 원하는 인쇄길이를 넘어선다면 stop!
				if (k38_prtCnt+2 > k38_print_len) break;
				k38_prtCnt = k38_prtCnt + 2; // 한글자 돌때마다 인쇄 칸 두칸 잡아먹기
				k38_ret = k38_ret + k38_a;
			}// if
		}// for
		int k38_cntBlank = k38_print_len - k38_prtCnt; // 원하는 칸수를 꽉 채우기 위해 필요한 공백의 갯수 계산
		for (int k38_i = 0; k38_i < k38_cntBlank; k38_i++) {
			k38_ret = " " + k38_ret; // 계산한 필요 공백 수만큼 위에서 나온 스트링의 앞에 공백 더하기
		}// for
		
		return k38_ret;
	}// k38_bblank;
	
	public static String k38_bblank(String k38_str, int k38_print_len) {
		String k38_ret = "";
		int k38_prtCnt = 0;
		for (int k38_i = 0; k38_i < k38_str.length(); k38_i++) { // String입력을 앞에서부터 한글자씩 검사
			String k38_a = k38_str.substring(k38_i, k38_i+1);
			if (k38_a.getBytes().length == 1) { // 해당 글자가 영문
				// 영문의 경우에는 한글자당 인쇄도 한칸, 인쇄할칸에 한글자가 더 왔을때 원하는 인쇄길이를 넘어선다면 stop!
				if (k38_prtCnt+1 > k38_print_len) break; 
				k38_prtCnt = k38_prtCnt + 1; // 한글자 돌때마다 인쇄 칸 한칸 잡아먹기
				k38_ret = k38_ret + k38_a; // 리턴할 스트링에 해당 문자 더하기
			} else { // 한글등(한글은 1글자당 인쇄칸을 2칸씩 먹는다)
				// 한글의 경우에는 한글자당 인쇄를 두칸, 인쇄할칸에 한글자(k38_prtCnt에 2가 더해짐)가 더 왔을때 원하는 인쇄길이를 넘어선다면 stop!
				if (k38_prtCnt+2 > k38_print_len) break;
				k38_prtCnt = k38_prtCnt + 2; // 한글자 돌때마다 인쇄 칸 두칸 잡아먹기
				k38_ret = k38_ret + k38_a;
			}// if
		}// for
		int k38_cntBlank = k38_print_len - k38_prtCnt; // 원하는 칸수를 꽉 채우기 위해 필요한 공백의 갯수 계산
		for (int k38_i = 0; k38_i < k38_cntBlank; k38_i++) {
			k38_ret = k38_ret + " "; // 계산한 필요 공백 수만큼 위에서 나온 스트링의 뒤에 공백 더하기
		}// for
		
		return k38_ret;
	}// k38_bblank;
	////////////////////
	/// 함수블록 종료 //
	////////////////////
	public static void main(String[] args) {
		/////////////////////////////////////
		/// 가운데 정렬 결정 관련 블록
//		String test = "emart";
//		int reqNum = k38_calcCenter(test, 12);
		///////////////////////////////////////
		
		Calendar k38_cld = Calendar.getInstance(); // 현재시간용
		Calendar k38_cld2 = Calendar.getInstance(); // 현재시간 - 1시간용
		k38_cld2.add(Calendar.HOUR_OF_DAY, -1); // cld2에 현재시간 - 1시간적용
		SimpleDateFormat k38_sdt = new SimpleDateFormat("YYYY-MM-dd HH:MM"); // 2021-03-03 21:17
		SimpleDateFormat k38_sdt2 = new SimpleDateFormat("YYYY-MM-dd HH:MM:ss"); // 2021-03-03 21:17:03
		SimpleDateFormat k38_sdt3 = new SimpleDateFormat("YYYYMMdd"); // 20210303
		String k38_currentTime = k38_sdt.format(k38_cld.getTime()); // 구매시간
		String k38_parkingTime = k38_sdt2.format(k38_cld2.getTime()); // 주차시간
		String k38_currentTime2 = k38_sdt3.format(k38_cld.getTime()); // 주차시간(- 빠진)
		
		DecimalFormat k38_df = new DecimalFormat("###,###,###,###,###"); // 숫자에 콤마

		double k38_tax_rate = 0.1; // 세율
		int k38_tf_total = 0; // 면세품목 합
		int k38_ntf_total = 0; // 과세품목 합
		int k38_ntf_net_total = 0;
		int k38_tax = 0; // 과세품목에 대한 부가세
		int k38_grand_total = 0; // 총계(면세품목 합 + 과세품목 합 + 과세품목에 대한 부가세)
		int k38_init_point = 120000; // 원래 가지고 있던 멤버쉽 포인트
		
		// 품목
		String[] k38_itemname = {"플레인요거트 450g", "비피더스 명장 기획", "서울 더진한 그릭요거트", "딸기 담은 요구르트", "서울 딸기우유", "서울 초코우유", "바나나우유", "삼양라면", "틈새라면", "핫브레이크 40입", 
				"도리토스 1kg", "롯데 초코파이", "선키스트 오렌지 주스", "삼각김밥 세트(3가지맛)", "컵라면 1box", "Cheetos Flamin Hot", "신선계란 30알(무항생제)", "캠벨 클램차우더 150g", "피코크 들깨미역국 500g", "몽쉘", 
				"케라시스 앰플 트리트먼트", "하루 한알 종합영양제", "미국산 한우 한근", "즉석 냉동 피자", "Nerf건(7세이상 아동용)", "하림 치킨너겟 1봉", "콜비잭 치즈 100개입", "LG모니터 24인치", "로지텍 마우스 g555", "AULA F108 기계식 키보드"};
		// 가격
		int[] k38_price = {2000000, 2500000, 1500000, 1000000, 3000, 2000, 2500, 4000, 5000, 6000, 
				1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
				11000, 12000, 13000, 14000, 15000, 16000, 17000, 1000000, 20000, 50000};
		// 수량
		int[] k38_num = {99, 1, 1, 1, 1, 2, 1, 1, 1, 2, 
				3, 1, 2, 1, 1, 2, 1, 2, 2, 1, 
				1, 1, 1, 2, 1, 1, 1, 10, 1, 1};
		// 면세여부
		boolean[] k38_taxfree = {false, false, false, false, true, false, false, true, false, false, 
				false, false, false, false, true, false, false, false, true, false, 
				false, true, false, false, false, false, true, false, false, false};
		
		//System.out.printf("12345678901234567890123456789012345678901\n");
		System.out.printf("%s%s\n", k38_bblank("", 12),k38_bblank("이마트 죽전점 (031)888-1234", 29));
		System.out.printf("%s%s\n", k38_bblank("    emart", 12),k38_bblank("206-86-50913 강희석", 29));
		System.out.printf("%s%s\n", k38_bblank("", 12),k38_bblank("용인 수지구 포은대로 552", 29));
		System.out.printf("%s\n", k38_bblank("영수증 미지참시 교환/환불 불가", 41));
		System.out.printf("%s\n", k38_bblank("정상상품에 한함, 30일 이내(신선 7일)", 41));
		System.out.printf("%s\n", k38_bblank("※일부 브랜드매장 제외(매장 고지물참조)", 41));
		System.out.printf("%s\n\n", k38_bblank("교환/환불 구매점에서 가능(결제카드 지참)", 41));
		System.out.printf("%s%s\n", k38_bblank("[구 매]"+k38_currentTime, 26), k38_fblank("POS:0011-9861", 15));
		System.out.printf("%s\n", k38_prtChars("-", 41));
		System.out.printf("%s%s%s%s\n",
				k38_bblank(" 상 품 명", 16),
				k38_fblank(" 단  가", 8),
				k38_fblank(" 수량", 6),
				k38_fblank(" 금  액", 11));
		System.out.printf("%s\n", k38_prtChars("-", 41));
		
		// 품목의 갯수만큼
		int k38_count = 0; // 품목의 갯수 카운트
		for (int k38_i=0; k38_i < k38_itemname.length; k38_i++) {
			if (k38_taxfree[k38_i] == true) { // 해당 품목이 면세대상이라면
				k38_count++; // 카운트 1개증가
				k38_itemname[k38_i] = "*" + k38_itemname[k38_i]; // 원래 스트링 앞에 *추가
				k38_tf_total = k38_tf_total + (k38_price[k38_i] * k38_num[k38_i]); // 면세 품목들의 합
				System.out.printf("%s%s%s%s\n",
						k38_bblank(k38_itemname[k38_i], 16),
						k38_fblank(k38_df.format(k38_price[k38_i]), 10),
						k38_fblank(k38_df.format(k38_num[k38_i]), 3),
						k38_fblank(k38_df.format(k38_price[k38_i] * k38_num[k38_i]), 12));
			} else if (k38_taxfree[k38_i] == false) { // 해당 품목이 면세대상이 아니라면
				k38_count++; // 카운트 1개증가
				k38_itemname[k38_i] = " " + k38_itemname[k38_i]; // 원래 스트링 앞에 공백 한개 추가
				k38_ntf_total = k38_ntf_total + (k38_price[k38_i] * k38_num[k38_i]); // 과세 품목들의 합
				System.out.printf("%s%s%s%s\n",
						k38_bblank(k38_itemname[k38_i], 16),
						k38_fblank(k38_df.format(k38_price[k38_i]), 10),
						k38_fblank(k38_df.format(k38_num[k38_i]), 3),
						k38_fblank(k38_df.format(k38_price[k38_i] * k38_num[k38_i]), 12));
			}// if
			if ((k38_count!=0) && ((k38_count) % 5 == 0)) { // 품목 5개 찍은 후 마다 점선 출력
				System.out.printf("%s\n", k38_prtChars("-", 41));
			}// if
		}//for
		k38_ntf_net_total = (int)(k38_ntf_total / (1 + k38_tax_rate)+0.000001); // 과세품목에 대한 세금
		k38_tax = k38_ntf_total - k38_ntf_net_total; // 과세품목에 대한 세금 계산
		k38_grand_total = k38_tf_total + k38_ntf_net_total + k38_tax; // 총 지불해야할 금액
		System.out.printf("\n%s%s%s\n", k38_fblank("", 15), k38_fblank("총 품목 수량", 12), k38_fblank(k38_df.format(k38_count), 14));
		System.out.printf("%s%s%s\n", k38_fblank("(*)", 15), k38_fblank("면 세  물 품", 12), k38_fblank(k38_df.format(k38_tf_total), 14));
		System.out.printf("%s%s%s\n", k38_fblank("", 15), k38_fblank("과 세  물 품", 12), k38_fblank(k38_df.format(k38_ntf_net_total), 14)); // 세전가격
		System.out.printf("%s%s%s\n", k38_fblank("", 15), k38_fblank("부   가   세", 12), k38_fblank(k38_df.format(k38_tax), 14));
		System.out.printf("%s%s%s\n", k38_fblank("", 15), k38_fblank("합        계", 12), k38_fblank(k38_df.format(k38_grand_total), 14)); // 면세물품 + 과세물품 + 부가세
		System.out.printf("%s%s\n", k38_bblank("결 제 대 상 금 액", 17), k38_fblank(k38_df.format(k38_grand_total), 24));
		System.out.printf("%s\n", k38_prtChars("-", 41));
		System.out.printf("%s%s\n", k38_bblank("0012 KEB 하나", 20), k38_fblank("541707**0484/35860658", 21));
		System.out.printf("%s%s\n", k38_bblank("카드결제(IC)", 20), k38_fblank("일시불 / " + k38_df.format(k38_grand_total), 21));
		System.out.printf("%s\n", k38_prtChars("-", 41));
		System.out.printf("%s\n", k38_fblank("[신세계포인트 적립]", 30));
		System.out.printf("%s\n", "홍*두 고객님의 포인트 현황입니다.");
		System.out.printf("%s%s%s\n", k38_bblank("금회발생포인트", 24), k38_bblank("9350**9995", 9), k38_fblank(k38_df.format((k38_grand_total)/1000), 8));
		System.out.printf("%s%s%s\n",
				k38_bblank("누계(가용)포인트", 22),
				k38_fblank(k38_df.format((k38_grand_total/1000) + k38_init_point) + "(", 10),
				k38_fblank(k38_df.format(k38_init_point) + ")", 9));
		System.out.printf("%s\n", k38_bblank("*신세계포인트 유효기간은 2년입니다.", 41));
		System.out.printf("%s\n", k38_prtChars("-", 41));
		System.out.printf("%s\n", k38_fblank("구매금액기준 무료주차시간 자동부여", 37));
		System.out.printf("%s%s\n", k38_bblank("차량번호 :", 21), k38_fblank("34저****", 20));
		System.out.printf("%s%s\n", k38_bblank("입차시간 :", 21), k38_fblank(k38_parkingTime, 20));
		System.out.printf("%s\n", k38_prtChars("-", 41));
		System.out.printf("%s%s\n", k38_bblank("캐셔:084599 양OO", 21), k38_fblank("1150", 20));
		System.out.printf("%s\n", k38_fblank("|||||||||||||||||||||||||||||||||||", 38));
		System.out.printf("%s\n", k38_fblank(k38_currentTime2 + "/00119861/00164980/31", 35)); // 현재시간 반영
		
	}// main

}// class
