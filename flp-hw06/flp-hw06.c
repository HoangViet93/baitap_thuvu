/*
 *	hovaten: Vu Thi Le Thu
 *	lop: D12CN8
 *	ngay sinh: 8-5-1994
 * 	msv: xxxx7
 */

/* Library include */
#include <stdio.h>
#include <time.h> 
#include <stdint.h>

/* Function prototype */
void bai601_main(void);
void bai602_main(void);
void bai603_main(void);
void bai604_main(void);
void bai605_main(void);
void bai606_main(void);
void bai607_main(void);

/*-----------------------------------------------------------------------------------------*/
/* MAIN PROGRAM */
int main(int argc, char **argv)
{
	char baitap[50] = {0};

	printf("Ho va ten : Vu Thi Le Thu \n");
	printf("Lop : D12CN8\n");
	printf("Ma Sinh Vien xxxx7\n");
	printf("FPL-HW6\n");

	while(1) {
		printf("Moi nhap : tenbaitap<6.xx>: ");
		scanf("%s", baitap);

		if (strcmp(baitap, "6.01") == 0) {
			bai601_main();
		}
		else if (strcmp(baitap, "6.02") == 0) {
			bai602_main();
		}
		else if (strcmp(baitap, "6.03") == 0) {
			bai603_main();
		}
		else if (strcmp(baitap, "6.04") == 0) {
			bai604_main();
		}
		else if (strcmp(baitap, "6.05") == 0) {
			bai605_main();
		}
		else if (strcmp(baitap, "6.06") == 0) {
			bai606_main();
		}
		else if (strcmp(baitap, "6.07") == 0) {
			bai607_main();
		}
		else {
			printf("em chua lam duoc xin loi thay a\n");
		}
	}
}	

/*-----------------------------------------------------------------------------------------*/
/* BAI 6.01 */

enum planet {
	Mercury = 0,
	Venus,
	Earth,
	Mars,
	Jupiter,
	Saturn,
	Uranus,
	Neptune,
	Pluto
};
char planet_eng_name[9][20] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
char planet_name[9][100] = {"sao thuy", "sao kim", "trai dat", "sao hoa", "sao moc", "sao tho", 
							"sao thien vuong", "sao hai vuong"};
char planet_describe[9][100] = {"gan mat troi nhat", "thu 2 tu mat troi", "duy nhat co su song", "gan trai dat nhat", 
								"lon nhat he mat troi", "dung thu 6 tu mat troi", "dung thu 7 tu mat troi", 
								"dung thu 8 tu mat troi", "mot mat trang cua sao thien vuong"};

void bai601_main(void)
{
	int i = 0;
	char buff[100];

	printf("BAI601 : \n");

	while(1) {  
		printf("Moi ban nhap vao hanh tinh ban quan tam : ");
		scanf("%s", buff);
		for (i = 0; i < 9; i++) {
			if (strcmp(buff, planet_eng_name[i]) == 0) {
				printf("ten tieng viet : %s\n", planet_name[i]);
				printf("Mieu ta : %s\n", planet_describe[i]);

				return;
			}
		}
		printf("Ban nhap sai ten moi nhap lai \n");
		for (i = 0; i < 9; i++) {
			printf("%s - ", planet_eng_name[i]);
		}
	}
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 6.02 */

enum season {
	SPRING = 0,
	SUMMER,
	AUTUMN,
	WINTER
};

typedef enum season season_t;

char season_name[4][20] = {"xuan", "ha", "thu", "dong"};

season_t bai602_get_season_by_month(int thang);

void bai602_main(void)
{	
	int thang = 0;
	season_t season;
	time_t raw_time;
	struct tm *full_time;

	printf("BAI602 : \n");

	printf("Moi ban nhap vao thang : ");
	scanf("%d", &thang);
	if (thang > 12 || thang < 1) {
		printf("Ban nhap sai thang\n");
	}
	
	season = bai602_get_season_by_month(thang);
	printf("thang %d la mua %s\n", thang, season_name[season]);

	time(&raw_time);
	full_time = localtime(&raw_time);
	printf("Bay gio la %s", asctime(full_time));
	season = bai602_get_season_by_month(full_time->tm_mon + 1);
	printf("Bay gio la thang %d la mua %s\n", full_time->tm_mon + 1, season_name[season]);
}

season_t bai602_get_season_by_month(int thang)
{
	if (thang > 11 || thang <= 2) {
		return WINTER;
	}
	else if (thang > 2 && thang <= 4) {
		return SPRING;
	}
	else if (thang > 4 && thang <= 7) {
		return SUMMER;
	}
	else {
		return AUTUMN;
	}	
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 6.03 */
typedef struct 
{
	char hovaten[40];
	char masinhvien[20];
	char lopquanly[20];
	float diemthi_hp;
	float diemkiemtra_giuaky;
	float diemkiemtra_ngan[10];
	int sobaikiemtra_ngan;
	int diem_danh;
	int solan_diemdanh;
	int diem_thuong;
	int diem_phat;
	float diembaitap[5];
	int sodiem_baitap;
	float diemtongket_so;
	char diemtongket_chu[5];
} sinhvien;

/* private variables */
char diem_chu[10][5] = {"F", "E", "D", "D+", "C", "C+", "B", "B+", "A", "A+"};

/* private function prototype */
void bai603_in_MaSVIn(sinhvien *sv, int sosinhvien);
void bai603_in_MaSVOut(char *file_name, sinhvien *sv, int sosinhvien);
void bai603_inthongtin(sinhvien *sv, int sosinhvien);
void bai603_read_file(sinhvien *sv, int sosinhvien);
void bai603_nhapthongtin(sinhvien *sv, char *ten, char *msv, char *lop);
void bai603_tinhdiemtongket(sinhvien *sv);
int bai603_tim_bang_msv(char *msv, sinhvien *sv, int sosinhvien);
int bai603_in_sv_diemcaonhat(sinhvien *sv, int sosinhvien);
int bai603_in_sv_diemthapnhat(sinhvien *sv, int sosinhvien);
int bai603_tinhdiem_tktrungbinh(sinhvien *sv, int sosinhvien);
int bai603_sosinhvien_trenmucdiem(float muc, sinhvien *sv, int sosinhvien);




void bai603_main(void)
{	
	int i = 0;
	sinhvien in_sv[4];
	sinhvien lop_sv[4];

	printf("BAI604 : \n");

	/* nhap thong tin */
	bai603_nhapthongtin(&in_sv[0], "VuThiLeThu", "B12CNCT007", "D12CN8");
	bai603_nhapthongtin(&in_sv[1], "HoangTheViet", "B12DCDT155", "D12DT3");
	bai603_nhapthongtin(&in_sv[2], "NguyenVanA", "B12DCDT156", "D12CN9");
	bai603_nhapthongtin(&in_sv[3], "NguyenVanB", "B12DCDT157", "D12CN10");

	/* ghi ra file */
	bai603_in_MaSVIn(in_sv, 4);
	/* doc tu file vao lop */
	bai603_read_file(lop_sv, 4);
	printf("thong tin sinh vien doc tu file MaSVIn.dat la : \n");
	bai603_inthongtin(lop_sv, 4);
	printf("------------------------------------------------------------\n");
	/* tinh diem tong ket */
	for (i = 0; i < 4; i++) {
		bai603_tinhdiemtongket(&lop_sv[i]);
	}
	/* in thong tin sinh vien da duoc tinh diem */
	bai603_in_MaSVOut("MaSVOut.dat", lop_sv, 4);
	/* tim sinh vien */
	bai603_tim_bang_msv("B12CNCT007", lop_sv, 4);
	printf("------------------------------------------------------------\n");
	/* tinh cac thong tin khac */
	bai603_in_sv_diemcaonhat(lop_sv, 4);
	printf("------------------------------------------------------------\n");
	bai603_in_sv_diemthapnhat(lop_sv, 4);
	printf("------------------------------------------------------------\n");
	bai603_tinhdiem_tktrungbinh(lop_sv, 4);
	bai603_sosinhvien_trenmucdiem(4, lop_sv, 4);
}

int bai603_sosinhvien_trenmucdiem(float muc, sinhvien *sv, int sosinhvien)
{
	int count = 0;
	int i = 0;

	for (i = 0; i < sosinhvien; i++) {
		if (sv->diemtongket_so >= muc) {
			count++;
		}
		sv++;
	}
	printf("Phan tram sinh vien tren muc diem %.1f la : %d% \n", muc, count * 100 / sosinhvien);
}

int bai603_tinhdiem_tktrungbinh(sinhvien *sv, int sosinhvien)
{
	float diemtk_tb = 0;
	int i = 0;

	for (i = 0; i < sosinhvien; i++) {
		diemtk_tb = diemtk_tb + sv->diemtongket_so;
		sv++;
	}
	diemtk_tb = diemtk_tb / sosinhvien;
	printf("diem tong ket trung binh cua lop la %.1f\n", diemtk_tb);
}

int bai603_in_sv_diemcaonhat(sinhvien *sv, int sosinhvien)
{
	int i, j = 0;
	sinhvien *sv_diemcao;

	sv_diemcao = sv;
	for (i = 0; i < sosinhvien - 1; i++) {
		sv++;
		if (sv_diemcao->diemtongket_so < sv->diemtongket_so) {
			sv_diemcao = sv;
		}
	}
	printf("Sinh vien diem tong ket cao nhat la : \n");	
	bai603_inthongtin(sv_diemcao, 1);
	bai603_in_MaSVOut("MaSVMaxOut.dat", sv_diemcao, 1);
}

int bai603_in_sv_diemthapnhat(sinhvien *sv, int sosinhvien)
{
	int i, j = 0;
	sinhvien *sv_diemthap;

	sv_diemthap = sv;
	for (i = 0; i < sosinhvien - 1; i++) {
		sv++;
		if (sv_diemthap->diemtongket_so > sv->diemtongket_so) {
			sv_diemthap = sv;
		}
	}
	printf("Sinh vien diem tong ket thap nhat la : \n");	
	bai603_inthongtin(sv_diemthap, 1);
	bai603_in_MaSVOut("MaSVMinOut.dat", sv_diemthap, 1);
}

int bai603_tim_bang_msv(char *msv, sinhvien *sv, int sosinhvien)
{
	int i, j = 0;

	for (i = 0; i < sosinhvien; i++) {
		if (strcmp(sv->masinhvien, msv) == 0) {
			printf("Tim thay sinh vien co msv %s\n", sv->masinhvien);
			bai603_inthongtin(sv, 1);
			break;
		}
		sv++;
	}
}

void bai603_inthongtin(sinhvien *sv, int sosinhvien)
{
	int i, j = 0;

	for (i = 0; i < sosinhvien; i++) {
		printf("ten sinh vien : %s\n", sv->hovaten);
		printf("msv : %s\n", sv->masinhvien);
		printf("lop : %s\n", sv->lopquanly);
		printf("diem thi hp : %.1f diem kiem tra giua ky : %.1f\n", sv->diemthi_hp, sv->diemkiemtra_giuaky);
		printf("so bai kiem tra ngan : %d\n", sv->sobaikiemtra_ngan);
		printf("diem kiem tra ngan : ");
		for (j = 0; j < sv->sobaikiemtra_ngan; j++) {
			printf("%.1f ", sv->diemkiemtra_ngan[i]);
		}
		printf("\n");
		printf("diem danh %d/%d\n", sv->diem_danh, sv->solan_diemdanh);
		printf("diem thuong %d va diem phat %d\n", sv->diem_thuong, sv->diem_phat);
		printf("so diem bai tap : %d\n", sv->sodiem_baitap);
		printf("diem bai tap %d: ", sv->sodiem_baitap);
		for (j = 0; j < sv->sodiem_baitap; j++) {
			printf("%.1f ", sv->diembaitap[j]);
		}
		printf("\n");
		printf("diem tong ket so : %.1f\n", sv->diemtongket_so);
		printf("diem tong ket dang chu : %s\n", sv->diemtongket_chu);
		printf("\n");
		sv++;
	}
}

void bai603_read_file(sinhvien *sv, int sosinhvien)
{
	FILE *file_p;
	int i, j = 0;

	file_p = fopen("MaSVIn.dat", "r");
	for (i = 0; i < sosinhvien; i++) {
		fscanf(file_p, "%s", sv->hovaten);
		fscanf(file_p, "%s", sv->masinhvien);
		fscanf(file_p, "%s", sv->lopquanly);
		fscanf(file_p, "%f", &sv->diemthi_hp);
		fscanf(file_p, "%f", &sv->diemkiemtra_giuaky);
		fscanf(file_p, "%d", &sv->sobaikiemtra_ngan);
		for (j = 0; j < sv->sobaikiemtra_ngan; j++) {
			fscanf(file_p, "%f", &sv->diemkiemtra_ngan[j]);
		}
		fscanf(file_p, "%d", &sv->diem_danh);
		fscanf(file_p, "%d", &sv->solan_diemdanh);
		fscanf(file_p, "%d", &sv->diem_thuong);
		fscanf(file_p, "%d", &sv->diem_phat);
		fscanf(file_p, "%d", &sv->sodiem_baitap);
		for (j = 0; j < sv->sodiem_baitap; j++) {
			fscanf(file_p, "%f", &sv->diembaitap[j]);
		}
		sv++;
	}
	fclose(file_p);		
}

void bai603_in_MaSVIn(sinhvien *sv, int sosinhvien)
{
	FILE *file_p;
	int i, j = 0;

	file_p = fopen("MaSVIn.dat", "w");
	for (i = 0; i < sosinhvien; i++) {
		fprintf(file_p, "%s\n", sv->hovaten);
		fprintf(file_p, "%s\n", sv->masinhvien);
		fprintf(file_p, "%s\n", sv->lopquanly);
		fprintf(file_p, "%f\n", sv->diemthi_hp);
		fprintf(file_p, "%f\n", sv->diemkiemtra_giuaky);
		fprintf(file_p, "%d\n", sv->sobaikiemtra_ngan);
		for (j = 0; j < sv->sobaikiemtra_ngan; j++) {
			fprintf(file_p, "%f\n", sv->diemkiemtra_ngan[j]);
		}
		fprintf(file_p, "%d\n", sv->diem_danh);
		fprintf(file_p, "%d\n", sv->solan_diemdanh);
		fprintf(file_p, "%d\n", sv->diem_thuong);
		fprintf(file_p, "%d\n", sv->diem_phat);
		fprintf(file_p, "%d\n", sv->sodiem_baitap);
		for (j = 0; j < sv->sodiem_baitap; j++) {
			fprintf(file_p, "%f\n", sv->diembaitap[j]);
		}
		fprintf(file_p, "\n");
		sv++;
	}
	fclose(file_p);	
}

void bai603_in_MaSVOut(char *file_name, sinhvien *sv, int sosinhvien)
{
	FILE *file_p;
	int i, j = 0;

	file_p = fopen(file_name, "w");
	for (i = 0; i < sosinhvien; i++) {
		fprintf(file_p, "ten sinh vien : %s\n", sv->hovaten);
		fprintf(file_p, "msv : %s\n", sv->masinhvien);
		fprintf(file_p, "lop : %s\n", sv->lopquanly);
		fprintf(file_p, "diem thi hp : %.1f diem kiem tra giua ky : %.1f\n", sv->diemthi_hp, sv->diemkiemtra_giuaky);
		fprintf(file_p, "so bai kiem tra ngan : %d\n", sv->sobaikiemtra_ngan);
		fprintf(file_p, "diem kiem tra ngan : ");
		for (j = 0; j < sv->sobaikiemtra_ngan; j++) {
			fprintf(file_p, "%.1f ", sv->diemkiemtra_ngan[i]);
		}
		fprintf(file_p, "\n");
		fprintf(file_p, "diem danh %d/%d\n", sv->diem_danh, sv->solan_diemdanh);
		fprintf(file_p, "diem thuong %d va diem phat %d\n", sv->diem_thuong, sv->diem_phat);
		fprintf(file_p, "so diem bai tap : %d\n", sv->sodiem_baitap);
		fprintf(file_p, "diem bai tap %d: ", sv->sodiem_baitap);
		for (j = 0; j < sv->sodiem_baitap; j++) {
			fprintf(file_p, "%.1f ", sv->diembaitap[j]);
		}
		fprintf(file_p, "\n");
		fprintf(file_p, "diem tong ket so : %.1f\n", sv->diemtongket_so);
		fprintf(file_p, "diem tong ket dang chu : %s\n", sv->diemtongket_chu);
		fprintf(file_p, "\n");
		sv++;
	}
}

void bai603_nhapthongtin(sinhvien *sv, char *ten, char *msv, char *lop)
{
	int i = 0;

	memset(sv->hovaten, '\0', 40);
	memset(sv->masinhvien, '\0', 20);
	memset(sv->lopquanly, '\0', 20);

	memcpy(sv->hovaten, ten, strlen(ten));
	memcpy(sv->masinhvien, msv, strlen(msv));
	memcpy(sv->lopquanly, lop, strlen(lop));

	/* random diem */
	sv->diemthi_hp = (rand() % 11) + (float)((rand() % 2) * 0.5);
	sv->diemkiemtra_giuaky = (rand() % 11) + (float)((rand() % 2) * 0.5);

	sv->sobaikiemtra_ngan = rand() % 10;
	for (i = 0; i < sv->sobaikiemtra_ngan; i++) {
		sv->diemkiemtra_ngan[i] = (rand() % 11) + (float)((rand() % 2) * 0.5);
	} 

	sv->sodiem_baitap = rand() % 5 + 1;
	for (i = 0; i < sv->sodiem_baitap; i++) {
		sv->diembaitap[i] = (rand() % 11) + (float)((rand() % 2) * 0.5);
	} 

	sv->solan_diemdanh = rand() % 5 + 1;
	sv->diem_danh = rand() % (sv->solan_diemdanh + 1) + 1;

	sv->diem_thuong = rand() % 5;
	sv->diem_phat = rand() % 5;
}

void bai603_tinhdiemtongket(sinhvien *sv)
{
	float diem_chuyencan = 0;
	float mid_term = 0;
	float diembaitap = 0;
	int i = 0;
	int tmp = 0;

	/* tinh diem chuyen can */
	tmp = (sv->diem_thuong - sv->diem_phat > 0) ? (sv->diem_thuong - sv->diem_phat) : 0;
	diem_chuyencan = 4 * (float)sv->diem_danh / sv->solan_diemdanh; //+ 6 * (tmp);

	/* tinh diem giua ky */
	for (i = 0; i < sv->sobaikiemtra_ngan; i++) {
		mid_term += sv->diemkiemtra_ngan[i];
	}
	mid_term = mid_term / sv->sobaikiemtra_ngan;
	mid_term = mid_term * 0.5 + sv->diemkiemtra_giuaky * 0.5;

	/* diem bai tap */
	for (i = 0; i < sv->sodiem_baitap; i++) {
		diembaitap += sv->diembaitap[i];
	}
	diembaitap = diembaitap / sv->sodiem_baitap;

	sv->diemtongket_so = 0.7 * sv->diemthi_hp + 0.1 * diembaitap + 0.1 * diem_chuyencan + 0.1 * mid_term;

	memset(sv->diemtongket_chu, '\0', 5);
	if (sv->diemtongket_so < 4) {
		memcpy(sv->diemtongket_chu, diem_chu[0], strlen(diem_chu[0]));
	}
	else if (sv->diemtongket_so < 5) {
		memcpy(sv->diemtongket_chu, diem_chu[1], strlen(diem_chu[1]));
	}
	else if (sv->diemtongket_so < 5.5) {
		memcpy(sv->diemtongket_chu, diem_chu[2], strlen(diem_chu[2]));		
	}
	else if (sv->diemtongket_so < 6) {
		memcpy(sv->diemtongket_chu, diem_chu[3], strlen(diem_chu[3]));		
	}
	else if (sv->diemtongket_so < 6.5) {
		memcpy(sv->diemtongket_chu, diem_chu[4], strlen(diem_chu[4]));		
	}
	else if (sv->diemtongket_so < 7) {
		memcpy(sv->diemtongket_chu, diem_chu[5], strlen(diem_chu[5]));		
	}
	else if (sv->diemtongket_so < 8) {
		memcpy(sv->diemtongket_chu, diem_chu[6], strlen(diem_chu[6]));		
	}
	else if (sv->diemtongket_so < 8.5) {
		memcpy(sv->diemtongket_chu, diem_chu[7], strlen(diem_chu[7]));		
	}
	else if (sv->diemtongket_so < 9) {
		memcpy(sv->diemtongket_chu, diem_chu[8], strlen(diem_chu[8]));		
	}
	else if (sv->diemtongket_so < 10) {
		memcpy(sv->diemtongket_chu, diem_chu[9], strlen(diem_chu[9]));		
	}
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 6.04 */

typedef struct 
{
	int ThangThu;
	char MaKH[20];
	char TenKH[40];
	char DiaChi[40];
	int SoDien_TieuThu;
} khachHang_Dien;

/* private function prototype */
int bai604_nhapThongTin(khachHang_Dien **kh);
void bai604_inthongtin_rafile(char *file_name, khachHang_Dien *kh, int soKH);
int bai604_khachhang_min(khachHang_Dien *kh, int soKH, int gia);
int bai604_khachhang_max(khachHang_Dien *kh, int soKH, int gia);
void bai604_phantram_khachhang(khachHang_Dien *kh, int soKH, int gia, int sotien);
void bai604_inhoadon(char *file_name, khachHang_Dien *kh, int soKH, int gia);
int bai604_tongsotien(khachHang_Dien *kh, int soKH, int gia);

void bai604_main(void)
{
	int N = 0;
	int sotien = 0;
	khachHang_Dien *ds_kh;

	printf("BAI604 : \n");

	N = bai604_nhapThongTin(&ds_kh);
	bai604_inthongtin_rafile("DSTDienIn.dat", ds_kh, N);
	bai604_inhoadon("BAI604_HoaDon.dat", ds_kh, N, 1000);

	bai604_tongsotien(ds_kh, N, 1000);
	bai604_khachhang_max(ds_kh, N, 1000);
	bai604_khachhang_min(ds_kh, N, 1000);

	printf("Moi ban nhap so tien muon kiem tra : ");
	scanf("%d", &sotien);
	bai604_phantram_khachhang(ds_kh, N, 1000, sotien);

	free(ds_kh);
}

void bai604_phantram_khachhang(khachHang_Dien *kh, int soKH, int gia, int sotien)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < soKH; i++) {
		if (kh->SoDien_TieuThu * gia >= sotien) {
			count++;
		}	
		kh++;
	}
	printf("Phan tram khach hang tieu thu cao hon %d la %d%\n", sotien, count * 100 / soKH);
}

int bai604_khachhang_max(khachHang_Dien *kh, int soKH, int gia)
{
	int i = 0;
	khachHang_Dien *kh_max = 0;

	kh_max = kh;
	for (i = 0; i < soKH - 1; i++) {
		kh++;
		if (kh_max->SoDien_TieuThu < kh->SoDien_TieuThu) {
			kh_max = kh;
		}	
	}
	printf("khach hang don gia cao nhat la : %s voi %d VND\n",kh_max->TenKH, kh_max->SoDien_TieuThu * gia);
}

int bai604_khachhang_min(khachHang_Dien *kh, int soKH, int gia)
{
	int i = 0;
	khachHang_Dien *kh_min = 0;

	kh_min = kh;
	for (i = 0; i < soKH - 1; i++) {
		kh++;
		if (kh_min->SoDien_TieuThu > kh->SoDien_TieuThu) {
			kh_min = kh;
		}	
	}
	printf("khach hang don gia thap nhat la : %s voi %d VND\n",kh_min->TenKH, kh_min->SoDien_TieuThu * gia);
}

int bai604_tongsotien(khachHang_Dien *kh, int soKH, int gia)
{
	int i = 0;
	int tongsotien = 0;

	for (i = 0; i < soKH; i++) {	
		tongsotien |= gia * kh->SoDien_TieuThu;
		kh++;
	}
	printf("Tong so tien so thu duoc %d\n", tongsotien);
}

void bai604_inhoadon(char *file_name, khachHang_Dien *kh, int soKH, int gia)
{
	int i = 0;
	FILE *file_p;

	file_p = fopen(file_name, "w");
	for (i = 0; i < soKH; i++) {
		fprintf(file_p, "Hoa don so %d\n", i + 1);
		fprintf(file_p, "Thang thu tien : %d\n", kh->ThangThu);
		fprintf(file_p, "Ma khach hang : %s\n", kh->MaKH);
		fprintf(file_p, "Ten khach hang : %s\n", kh->TenKH);
		fprintf(file_p, "Dia chi : %s\n", kh->DiaChi);
		fprintf(file_p, "So dien tieu thu : %d\n", kh->SoDien_TieuThu);
		fprintf(file_p, "Don Gia : %d VND\n", kh->SoDien_TieuThu * gia);		
		fprintf(file_p, "-----------------------------------------------------\n");
		kh++;
	}	
}

void bai604_inthongtin_rafile(char *file_name, khachHang_Dien *kh, int soKH)
{
	int i = 0;
	FILE *file_p;

	file_p = fopen(file_name, "w");
	for (i = 0; i < soKH; i++) {
		fprintf(file_p, "thong tin so %d\n", i + 1);
		fprintf(file_p, "Thang thu tien : %d\n", kh->ThangThu);
		fprintf(file_p, "Ma khach hang : %s\n", kh->MaKH);
		fprintf(file_p, "Ten khach hang : %s\n", kh->TenKH);
		fprintf(file_p, "Dia chi : %s\n", kh->DiaChi);
		fprintf(file_p, "So dien tieu thu : %d\n", kh->SoDien_TieuThu);
		fprintf(file_p, "-----------------------------------------------------\n");
		kh++;
	}
}

int bai604_nhapThongTin(khachHang_Dien **kh) 
{	
	int soKH = 0;
	int i = 0;
	int tmp = 0;
	khachHang_Dien *tmp_kh;
	printf("bai604_nhapThongTin\n");

	printf("Moi Nhap So Khach hang : ");
	scanf("%d", &soKH);
	*kh = (khachHang_Dien*)malloc(sizeof(khachHang_Dien) * soKH);
	tmp_kh = *kh;

	for (i = 0; i < soKH; i++) {
		printf("Ban dang nhap khach hang thu %d/%d\n", i + 1, soKH);
		printf("Moi nhap thang thu tien : ");
		scanf("%d", &tmp_kh->ThangThu);

		printf("Moi nhap ma KH <no space>: ");
		scanf("%s", tmp_kh->MaKH);

		printf("Moi nhap ten KH <no space>: ");
    	scanf("%s", tmp_kh->TenKH);

		printf("Moi nhap dia chi <no space>: ");
   	 	scanf("%s", tmp_kh->DiaChi);

		printf("Moi nhap so dien tieu thu <no space>: ");
		scanf("%d", &tmp);

		tmp_kh->SoDien_TieuThu = tmp;
		tmp_kh++;
	}
	return soKH;
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 6.05 */
typedef union {
	char type_char[60];
	float type_float;
	int type_int;
} union_var_t;

void bai605_main(void)
{
	union_var_t var;

	printf("BAI605 : \n");

	var.type_int = 5;
	printf("ghi vao var union gia tri nguyen 5 ta duoc \n");
	printf("var.type_int : %d\n", var.type_int);
	printf("var.type_int : %f\n", var.type_float);
	printf("var.type_int : %s\n", var.type_char);

	var.type_float = 5.6;
	printf("ghi vao var union gia tri thuc 5.6 ta duoc \n");
	printf("var.type_int : %d\n", var.type_int);
	printf("var.type_int : %f\n", var.type_float);
	printf("var.type_int : %s\n", var.type_char);

	memcpy(var.type_char, "em chao thay a", strlen("em chao thay a"));
	printf("ghi vao var union chuoi em chao thay a ta duoc \n");
	printf("var.type_int : %d\n", var.type_int);
	printf("var.type_int : %f\n", var.type_float);
	printf("var.type_int : %s\n", var.type_char);
}
/*-----------------------------------------------------------------------------------------*/




/*-----------------------------------------------------------------------------------------*/
/* BAI 6.06 */
struct 
{
	/* power line */
	uint16_t vss : 1;
	uint16_t vcc : 1;
	uint16_t vee : 1;

	/* control line */
	uint16_t rs : 1;
	uint16_t rw : 1;
	uint16_t en : 1;

	/* data line */
	uint16_t db : 8;

	/* back light led */
	uint16_t bpl : 1;
	uint16_t gnd : 1;
} lcd16x2_control;

void bai606_main(void)
{
	printf("BAI606 : \n");

	printf("size of bit field of lcd16x2_control is %d byte\n", sizeof(lcd16x2_control));
	lcd16x2_control.db = 0xF1;
	printf("value of data line (DB0->DB7) of bit field is %X\n", lcd16x2_control.db);
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 6.07 */

struct listnode
{
	char data;
	struct listnode *next_p;	
};

typedef struct listnode listnode_t;

void bai607_insert(listnode_t **sPtr, char data);
int bai607_print_list(listnode_t *ptr);
char bai607_delete(listnode_t **sPtr, char data);

void bai607_main(void)
{
	listnode_t *sPtr = NULL;

	bai607_insert(&sPtr, 'A');	
	bai607_insert(&sPtr, 'B');	
	bai607_insert(&sPtr, 'C');	
	bai607_insert(&sPtr, 'D');	
	bai607_print_list(sPtr);
	printf("delete node C \n");
	bai607_delete(&sPtr, 'C');
	bai607_print_list(sPtr);

	/* free memory */
	bai607_delete(&sPtr, 'A');
	bai607_delete(&sPtr, 'B');
	bai607_delete(&sPtr, 'D');
}

void bai607_insert(listnode_t **sPtr, char data)
{
	listnode_t *current_p;
	listnode_t *new_node;
	listnode_t *previous_p;	

	new_node = (listnode_t*)malloc(sizeof(listnode_t));
	new_node->data = data;
	new_node->next_p = NULL;

	previous_p = NULL;
	current_p = *sPtr;

	while(current_p != NULL && data > current_p->data) {
		previous_p = current_p;
		current_p = current_p->next_p;
	}
	if (previous_p == NULL) {
		new_node->next_p = *sPtr;
		*sPtr = new_node;
	}
	else {
		previous_p->next_p = new_node;
		new_node->next_p = current_p;
	}
}

char bai607_delete(listnode_t **sPtr, char data)
{
	listnode_t *current_p;
	listnode_t *temp_p;
	listnode_t *previous_p;	
	
	if (data == (*sPtr)->data) {
		temp_p = *sPtr;
		*sPtr = (*sPtr)->next_p;
		free(temp_p);
		return data;
	}
	else {
		previous_p = *sPtr;
		current_p = (*sPtr)->next_p;
		
		while(current_p != NULL && current_p->data != data) {
			previous_p = current_p;
			current_p = current_p->next_p;	
		}

		if (current_p != NULL) {
			temp_p = current_p;
			previous_p->next_p = current_p->next_p;
			free(temp_p);
			return data;
		}
	}
	return '\0';	
}

int bai607_is_empty(listnode_t *ptr)
{
	return (ptr == NULL);
}

int bai607_print_list(listnode_t *ptr)
{
	if (bai607_is_empty(ptr)) {
		puts("linked list empty");
	}
	while(ptr != NULL) {
		printf("%c --> ", ptr->data);
		ptr = ptr->next_p;
	}

	printf("NULL\n");	
}