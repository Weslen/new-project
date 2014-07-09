#include "ShuRuFa.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "key.h"
#include "lcd.h"
#include "mypure_library.h"
#include "my_library.h"
#include "my_stdint.h"
#include "setting.h"
#include "FoodOrder.h"


typedef struct
{
	const u8 *T9;
	const u8 *PY;
	const u8 *MB;
} T9PY_IDX;

static short cursorX;
static short cursorY;


//#define AddBiHuaPinYin


#ifdef AddBiHuaPinYin
const u8 PY_mb_space [] = {"  "};
const u8 PY_mb_fuhao [] = {"���������������������������������������ã�������������������������������������������ۣݣ����֡ܡݣ����ڡۣ������£��ҡӡءޡġšơǡȡɡʡ͡ΡϡСѡա�"};
const u8 PY_mb_a     [] = {"����"};
const u8 PY_mb_ai    [] = {"��������������������������"};
const u8 PY_mb_an    [] = {"������������������"};
const u8 PY_mb_ang   [] = {"������"};
const u8 PY_mb_ao    [] = {"���������°����ð�"};
const u8 PY_mb_b     [] = {"�˰װ��"}; ////
const u8 PY_mb_ba    [] = {"�˰ѰͰְհ԰ΰǰɰӰṴ̋ưʰϰȰ�"};
const u8 PY_mb_bai   [] = {"�װٰڰܰݰ۰ذ�"};
const u8 PY_mb_ban   [] = {"�������������߰���"};
const u8 PY_mb_bang  [] = {"�������������������"};
const u8 PY_mb_bao   [] = {"������������������������������������"};
const u8 PY_mb_bei   [] = {"������������������������������"};
const u8 PY_mb_ben   [] = {"����������"};
const u8 PY_mb_beng  [] = {"�����±ñű�"};
const u8 PY_mb_bi    [] = {"�ƱǱȱ˱ʱɱұرϱձӱѱݱбֱԱͱױ̱αڱܱ�"};
const u8 PY_mb_bian  [] = {"�߱�ޱ���������"};
const u8 PY_mb_biao  [] = {"�����"};
const u8 PY_mb_bie   [] = {"�����"};
const u8 PY_mb_bin   [] = {"����������"};
const u8 PY_mb_bing  [] = {"������������������"};
const u8 PY_mb_bo    [] = {"����������������������������������������"};
const u8 PY_mb_bu    [] = {"��������������������"};
const u8 PY_mb_c     [] = {"���²β�"}; ///
const u8 PY_mb_ca    [] = {"��"};
const u8 PY_mb_cai   [] = {"�²ŲĲƲòɲʲǲȲ˲�"};
const u8 PY_mb_can   [] = {"�βͲвϲѲҲ�"};
const u8 PY_mb_cang  [] = {"�ֲײԲղ�"};
const u8 PY_mb_cao   [] = {"�ٲڲܲ۲�"};
const u8 PY_mb_ce    [] = {"���޲��"};
const u8 PY_mb_ceng  [] = {"�����"};
const u8 PY_mb_cha   [] = {"�������������ɲ"};
const u8 PY_mb_chai  [] = {"����"};
const u8 PY_mb_chan  [] = {"�������������������"};
const u8 PY_mb_chang [] = {"������������������������"};
const u8 PY_mb_chao  [] = {"��������������������"};
const u8 PY_mb_che   [] = {"������������"};
const u8 PY_mb_chen  [] = {"�������������³��ĳ�"};
const u8 PY_mb_cheng [] = {"�Ƴųɳʳгϳǳ˳ͳ̳γȳѳҳ�"};
const u8 PY_mb_chi   [] = {"�Գճڳس۳ٳֳ߳޳ݳܳ����"};
const u8 PY_mb_chong [] = {"������"};
const u8 PY_mb_chou  [] = {"��������������"};
const u8 PY_mb_chu   [] = {"����������������������������������"};
const u8 PY_mb_chuai [] = {"��"};
const u8 PY_mb_chuan [] = {"��������������"};
const u8 PY_mb_chuang[] = {"����������"};
const u8 PY_mb_chui  [] = {"����������"};
const u8 PY_mb_chun  [] = {"��������������"};
const u8 PY_mb_chuo  [] = {"��"};
const u8 PY_mb_ci    [] = {"�ôʴĴɴȴǴŴƴ˴δ̴�"};
const u8 PY_mb_cong  [] = {"�ѴӴҴдϴ�"};
const u8 PY_mb_cou   [] = {"��"};
const u8 PY_mb_cu    [] = {"�ִٴ״�"};
const u8 PY_mb_cuan  [] = {"�ڴܴ�"};
const u8 PY_mb_cui   [] = {"�޴ߴݴ�����"};
const u8 PY_mb_cun   [] = {"����"};
const u8 PY_mb_cuo   [] = {"�������"};
const u8 PY_mb_d     [] = {"�������"}; ///
const u8 PY_mb_da    [] = {"�������"};
const u8 PY_mb_dai   [] = {"������������������������"};
const u8 PY_mb_dan   [] = {"������������������������������"};
const u8 PY_mb_dang  [] = {"����������"};
const u8 PY_mb_dao   [] = {"������������������������"};
const u8 PY_mb_de    [] = {"�õµ�"};
const u8 PY_mb_deng  [] = {"�Ƶǵŵȵ˵ʵ�"};
const u8 PY_mb_di    [] = {"�͵̵εҵϵеӵѵյ׵ֵصܵ۵ݵڵ޵�"};
const u8 PY_mb_dian  [] = {"���ߵ��������������"};
const u8 PY_mb_diao  [] = {"�����������"};
const u8 PY_mb_die   [] = {"��������������"};
const u8 PY_mb_ding  [] = {"������������������"};
const u8 PY_mb_diu   [] = {"��"};
const u8 PY_mb_dong  [] = {"��������������������"};
const u8 PY_mb_dou   [] = {"����������������"};
const u8 PY_mb_du    [] = {"�����������¶ĶöʶŶǶȶɶ�"};
const u8 PY_mb_duan  [] = {"�˶̶ζ϶ж�"};
const u8 PY_mb_dui   [] = {"�ѶӶԶ�"};
const u8 PY_mb_dun   [] = {"�ֶضն׶ܶ۶ٶ�"};
const u8 PY_mb_duo   [] = {"��߶�޶��������"};
const u8 PY_mb_e     [] = {"�����������������"};
const u8 PY_mb_en    [] = {"��"};
const u8 PY_mb_er    [] = {"����������������"};
const u8 PY_mb_f     [] = {"�������ɷ�"}; ///
const u8 PY_mb_fa    [] = {"����������������"};
const u8 PY_mb_fan   [] = {"����������������������������������"};
const u8 PY_mb_fang  [] = {"���������������·÷ķ�"};
const u8 PY_mb_fei   [] = {"�ɷǷȷƷʷ˷̷ͷϷзη�"};
const u8 PY_mb_fen   [] = {"�ַԷ׷ҷշӷطڷٷ۷ݷܷ޷߷�"};
const u8 PY_mb_feng  [] = {"�����������������"};
const u8 PY_mb_fo    [] = {"��"};
const u8 PY_mb_fou   [] = {"��"};
const u8 PY_mb_fu    [] = {"������󸥷�����������������������������������������������������������������������������"};
const u8 PY_mb_g     [] = {"�¸øɸԸ�"}; ///
const u8 PY_mb_ga    [] = {"�¸�"};
const u8 PY_mb_gai   [] = {"�øĸƸǸȸ�"};
const u8 PY_mb_gan   [] = {"�ɸʸ˸θ̸͸ѸϸҸи�"};
const u8 PY_mb_gang  [] = {"�Ըոڸٸظ׸ָ۸�"};
const u8 PY_mb_gao   [] = {"�޸�߸�ݸ�����"};
const u8 PY_mb_ge    [] = {"�����������������������"};
const u8 PY_mb_gei   [] = {"��"};
const u8 PY_mb_gen   [] = {"����"};
const u8 PY_mb_geng  [] = {"��������������"};
const u8 PY_mb_gong  [] = {"������������������������������"};
const u8 PY_mb_gou   [] = {"������������������"};
const u8 PY_mb_gu    [] = {"�����ù¹��������ŹȹɹǹƹĹ̹ʹ˹�"};
const u8 PY_mb_gua   [] = {"�Ϲιйѹҹ�"};
const u8 PY_mb_guai  [] = {"�Թչ�"};
const u8 PY_mb_guan  [] = {"�ع۹ٹڹ׹ݹܹ�߹��"};
const u8 PY_mb_guang [] = {"����"};
const u8 PY_mb_gui   [] = {"�������������������"};
const u8 PY_mb_gun   [] = {"������"};
const u8 PY_mb_guo   [] = {"������������"};
const u8 PY_mb_h     [] = {"�򺢺�����"}; ///
const u8 PY_mb_ha    [] = {"���"};
const u8 PY_mb_hai   [] = {"��������������"};
const u8 PY_mb_han   [] = {"��������������������������������������"};
const u8 PY_mb_hang  [] = {"������"};
const u8 PY_mb_hao   [] = {"���������úºźƺ�"};
const u8 PY_mb_he    [] = {"�ǺȺ̺ϺκͺӺҺ˺ɺԺкʺغֺպ�"};
const u8 PY_mb_hei   [] = {"�ں�"};
const u8 PY_mb_hen   [] = {"�ۺܺݺ�"};
const u8 PY_mb_heng  [] = {"��ߺ���"};
const u8 PY_mb_hong  [] = {"����������"};
const u8 PY_mb_hou   [] = {"���������"};
const u8 PY_mb_hu    [] = {"������������������������������������"};
const u8 PY_mb_hua   [] = {"������������������"};
const u8 PY_mb_huai  [] = {"����������"};
const u8 PY_mb_huan  [] = {"�����������û»�������������"};
const u8 PY_mb_huang [] = {"�ĻŻʻ˻ƻ̻ͻȻǻɻлλѻ�"};
const u8 PY_mb_hui   [] = {"�һֻӻԻջػ׻ڻܻ������߻޻�ݻٻ�"};
const u8 PY_mb_hun   [] = {"�������"};
const u8 PY_mb_huo   [] = {"��������������"};
const u8 PY_mb_j     [] = {"���Ӽ齭��"}; ///
const u8 PY_mb_ji    [] = {"���������������������������������������������������������������������ƼǼ��ͼ˼ɼ��ʼ����ȼü̼żļ¼�������"};
const u8 PY_mb_jia   [] = {"�ӼмѼϼҼμԼռ׼ּؼۼݼܼټ޼�Ю"};
const u8 PY_mb_jian  [] = {"����߼�����������������������������������������������������"};
const u8 PY_mb_jiang [] = {"��������������������������"};
const u8 PY_mb_jiao  [] = {"���������������������ǽƽʽȽýŽ½��˽ɽнνϽ̽ѽ;���"};
const u8 PY_mb_jie   [] = {"�׽Խӽսҽֽڽٽܽ��ݽ޽ؽ߽����������"};
const u8 PY_mb_jin   [] = {"����������������������������������"};
const u8 PY_mb_jing  [] = {"��������������������������������������������������"};
const u8 PY_mb_jiong [] = {"����"};
const u8 PY_mb_jiu   [] = {"�������žþľ��¾ƾɾʾ̾ξǾȾ;�"};
const u8 PY_mb_ju    [] = {"�ӾоѾԾҾϾֽ۾վ׾ھپؾ�޾ܾ߾����ݾ��۾�"};
const u8 PY_mb_juan  [] = {"���������"};
const u8 PY_mb_jue   [] = {"��������������"};
const u8 PY_mb_jun   [] = {"����������������������"};
const u8 PY_mb_k     [] = {"����������"}; ///
const u8 PY_mb_ka    [] = {"������"};
const u8 PY_mb_kai   [] = {"����������"};
const u8 PY_mb_kan   [] = {"��������������"};
const u8 PY_mb_kang  [] = {"��������������"};
const u8 PY_mb_kao   [] = {"��������"};
const u8 PY_mb_ke    [] = {"�����¿ƿÿſĿǿȿɿʿ˿̿Ϳ�"};
const u8 PY_mb_ken   [] = {"�Ͽѿҿ�"};
const u8 PY_mb_keng  [] = {"�Կ�"};
const u8 PY_mb_kong  [] = {"�տ׿ֿ�"};
const u8 PY_mb_kou   [] = {"�ٿڿۿ�"};
const u8 PY_mb_ku    [] = {"�ݿ޿߿����"};
const u8 PY_mb_kua   [] = {"������"};
const u8 PY_mb_kuai  [] = {"�����"};
const u8 PY_mb_kuan  [] = {"����"};
const u8 PY_mb_kuang [] = {"�����������"};
const u8 PY_mb_kui   [] = {"����������������������"};
const u8 PY_mb_kun   [] = {"��������"};
const u8 PY_mb_kuo   [] = {"��������"};
const u8 PY_mb_l     [] = {"����������"}; ///
const u8 PY_mb_la    [] = {"��������������"};
const u8 PY_mb_lai   [] = {"������"};
const u8 PY_mb_lan   [] = {"������������������������������"};
const u8 PY_mb_lang  [] = {"��������������"};
const u8 PY_mb_lao   [] = {"������������������"};
const u8 PY_mb_le    [] = {"������"};
const u8 PY_mb_lei   [] = {"����������������������"};
const u8 PY_mb_leng  [] = {"������"};
const u8 PY_mb_li    [] = {"��������������������������������������������������������������������"};
const u8 PY_mb_lian  [] = {"����������������������������"};
const u8 PY_mb_liang [] = {"������������������������"};
const u8 PY_mb_liao  [] = {"������������������������"};
const u8 PY_mb_lie   [] = {"����������"};
const u8 PY_mb_lin   [] = {"������������������������"};
const u8 PY_mb_ling  [] = {"����������������������������"};
const u8 PY_mb_liu   [] = {"����������������������"};
const u8 PY_mb_long  [] = {"��������¡��¤¢£"};
const u8 PY_mb_lou   [] = {"¦¥§¨ª©"};
const u8 PY_mb_lu    [] = {"¶¬®«¯­±²°³½¼¸¹»µ·¾º´"};
const u8 PY_mb_luan  [] = {"������������"};
const u8 PY_mb_lue   [] = {"����"};
const u8 PY_mb_lun   [] = {"��������������"};
const u8 PY_mb_luo   [] = {"������������������������"};
const u8 PY_mb_lv    [] = {"��¿������������������������"};
const u8 PY_mb_m     [] = {"������æè"}; ///
const u8 PY_mb_ma    [] = {"������������������"};
const u8 PY_mb_mai   [] = {"������������"};
const u8 PY_mb_man   [] = {"����������á������"};
const u8 PY_mb_mang  [] = {"æâäãçå"};
const u8 PY_mb_mao   [] = {"èëìéêîíïðóñò"};
const u8 PY_mb_me    [] = {"ô"};
const u8 PY_mb_mei   [] = {"ûöõü÷ýúøùÿ��þ��������"};
const u8 PY_mb_men   [] = {"������"};
const u8 PY_mb_meng  [] = {"����������������"};
const u8 PY_mb_mi    [] = {"����������������������������"};
const u8 PY_mb_mian  [] = {"������������������"};
const u8 PY_mb_miao  [] = {"����������������"};
const u8 PY_mb_mie   [] = {"����"};
const u8 PY_mb_min   [] = {"������������"};
const u8 PY_mb_ming  [] = {"������������"};
const u8 PY_mb_miu   [] = {"��"};
const u8 PY_mb_mo    [] = {"����ġģĤĦĥĢħĨĩĭİĪįĮīĬ"};
const u8 PY_mb_mou   [] = {"Ĳıĳ"};
const u8 PY_mb_mu    [] = {"ĸĶĵķĴľĿ��ļĹĻ��Ľĺ��"};
const u8 PY_mb_n     [] = {"������"}; ///
const u8 PY_mb_na    [] = {"��������������"};
const u8 PY_mb_nai   [] = {"����������"};
const u8 PY_mb_nan   [] = {"�������"};
const u8 PY_mb_nang  [] = {"��"};
const u8 PY_mb_nao   [] = {"����������"};
const u8 PY_mb_ne    [] = {"��"};
const u8 PY_mb_nei   [] = {"����"};
const u8 PY_mb_nen   [] = {"��"};
const u8 PY_mb_neng  [] = {"��"};
const u8 PY_mb_ni    [] = {"����������������������"};
const u8 PY_mb_nian  [] = {"��������������"};
const u8 PY_mb_niang [] = {"����"};
const u8 PY_mb_niao  [] = {"����"};
const u8 PY_mb_nie   [] = {"��������������"};
const u8 PY_mb_nin   [] = {"��"};
const u8 PY_mb_ning  [] = {"��š������Ţ"};
const u8 PY_mb_niu   [] = {"ţŤŦť"};
const u8 PY_mb_nong  [] = {"ũŨŧŪ"};
const u8 PY_mb_nu    [] = {"ūŬŭ"};
const u8 PY_mb_nuan  [] = {"ů"};
const u8 PY_mb_nue   [] = {"űŰ"};
const u8 PY_mb_nuo   [] = {"ŲŵųŴ"};
const u8 PY_mb_nv    [] = {"Ů"};
const u8 PY_mb_o     [] = {"Ŷ"};
const u8 PY_mb_ou    [] = {"ŷŹŸŻżźŽ"};
const u8 PY_mb_p     [] = {"ſ������"}; ///
const u8 PY_mb_pa    [] = {"ſž����������"};
const u8 PY_mb_pai   [] = {"������������"};
const u8 PY_mb_pan   [] = {"����������������"};
const u8 PY_mb_pang  [] = {"����������"};
const u8 PY_mb_pao   [] = {"��������������"};
const u8 PY_mb_pei   [] = {"������������������"};
const u8 PY_mb_pen   [] = {"����"};
const u8 PY_mb_peng  [] = {"����������������������������"};
const u8 PY_mb_pi    [] = {"��������������Ƥ��ƣơ��ƢƥƦƨƧƩ"};
const u8 PY_mb_pian  [] = {"Ƭƫƪƭ"};
const u8 PY_mb_piao  [] = {"ƯƮưƱ"};
const u8 PY_mb_pie   [] = {"ƲƳ"};
const u8 PY_mb_pin   [] = {"ƴƶƵƷƸ"};
const u8 PY_mb_ping  [] = {"ƽ��ƾ��ƿƺƻƼƹ"};
const u8 PY_mb_po    [] = {"����������������"};
const u8 PY_mb_pou   [] = {"��"};
const u8 PY_mb_pu    [] = {"������������������������������"};
const u8 PY_mb_q     [] = {"����ǧǺ"}; ///
const u8 PY_mb_qi    [] = {"������������������������������������������������������������������������"};
const u8 PY_mb_qia   [] = {"��ǡǢ"};
const u8 PY_mb_qian  [] = {"ǧǪǤǨǥǣǦǫǩǰǮǯǬǱǭǳǲǴǷǵǶǸ"};
const u8 PY_mb_qiang [] = {"ǺǼǹǻǿǽǾ��"};
const u8 PY_mb_qiao  [] = {"������������������������������"};
const u8 PY_mb_qie   [] = {"����������"};
const u8 PY_mb_qin   [] = {"����������������������"};
const u8 PY_mb_qing  [] = {"��������������������������"};
const u8 PY_mb_qiong [] = {"����"};
const u8 PY_mb_qiu   [] = {"����������������"};
const u8 PY_mb_qu    [] = {"����������������ȡȢȣȥȤ"};
const u8 PY_mb_quan  [] = {"ȦȫȨȪȭȬȩȧȮȰȯ"};
const u8 PY_mb_que   [] = {"Ȳȱȳȴȸȷȵȶ"};
const u8 PY_mb_qun   [] = {"ȹȺ"};
const u8 PY_mb_r     [] = {"Ȼȿ��"}; ///
const u8 PY_mb_ran   [] = {"ȻȼȽȾ"};
const u8 PY_mb_rang  [] = {"ȿ��������"};
const u8 PY_mb_rao   [] = {"������"};
const u8 PY_mb_re    [] = {"����"};
const u8 PY_mb_ren   [] = {"��������������������"};
const u8 PY_mb_reng  [] = {"����"};
const u8 PY_mb_ri    [] = {"��"};
const u8 PY_mb_rong  [] = {"��������������������"};
const u8 PY_mb_rou   [] = {"������"};
const u8 PY_mb_ru    [] = {"��������������������"};
const u8 PY_mb_ruan  [] = {"����"};
const u8 PY_mb_rui   [] = {"������"};
const u8 PY_mb_run   [] = {"����"};
const u8 PY_mb_ruo   [] = {"����"};
const u8 PY_mb_s     [] = {"������"}; ///
const u8 PY_mb_sa    [] = {"������"};
const u8 PY_mb_sai   [] = {"��������"};
const u8 PY_mb_san   [] = {"��ɡɢ��"};
const u8 PY_mb_sang  [] = {"ɣɤɥ"};
const u8 PY_mb_sao   [] = {"ɦɧɨɩ"};
const u8 PY_mb_se    [] = {"ɫɬɪ"};
const u8 PY_mb_sen   [] = {"ɭ"};
const u8 PY_mb_seng  [] = {"ɮ"};
const u8 PY_mb_sha   [] = {"ɱɳɴɰɯɵɶɷ��"};
const u8 PY_mb_shai  [] = {"ɸɹ"};
const u8 PY_mb_shan  [] = {"ɽɾɼ��ɺɿ������ɻ������������դ"};
const u8 PY_mb_shang [] = {"����������������"};
const u8 PY_mb_shao  [] = {"����������������������"};
const u8 PY_mb_she   [] = {"������������������������"};
const u8 PY_mb_shen  [] = {"��������������������������������ʲ"};
const u8 PY_mb_sheng [] = {"��������ʤ����ʡʥʢʣ"};
const u8 PY_mb_shi   [] = {"��ʮʯʱʿʶ��ʳʾʽʹʼ����ʵ����ʷ��ʩ��ʻʪ�Ƴ�ʬʧ����ʦʭʫʨʰʴʸʺ����������������������"};
const u8 PY_mb_shou  [] = {"��������������������"};
const u8 PY_mb_shu   [] = {"������������������������������������������������������ˡ����������"};
const u8 PY_mb_shua  [] = {"ˢˣ"};
const u8 PY_mb_shuai [] = {"˥ˤ˦˧"};
const u8 PY_mb_shuan [] = {"˩˨"};
const u8 PY_mb_shuang[] = {"˫˪ˬ"};
const u8 PY_mb_shui  [] = {"˭ˮ˰˯"};
const u8 PY_mb_shun  [] = {"˱˳˴˲"};
const u8 PY_mb_shuo  [] = {"˵˸˷˶"};
const u8 PY_mb_si    [] = {"��˿˾˽˼˹��˺��˻����������"};
const u8 PY_mb_song  [] = {"����������������"};
const u8 PY_mb_sou   [] = {"��������"};
const u8 PY_mb_su    [] = {"����������������������"};
const u8 PY_mb_suan  [] = {"������"};
const u8 PY_mb_sui   [] = {"����������������������"};
const u8 PY_mb_sun   [] = {"������"};
const u8 PY_mb_suo   [] = {"����������������"};
const u8 PY_mb_t     [] = {"��̥̮��"}; ///
const u8 PY_mb_ta    [] = {"����������̡̢̤̣"};
const u8 PY_mb_tai   [] = {"̨̧̥̦̫̭̬̩̪"};
const u8 PY_mb_tan   [] = {"̸̵̷̶̴̮̰̯̲̱̳̹̻̺̼̾̿̽"};
const u8 PY_mb_tang  [] = {"��������������������������"};
const u8 PY_mb_tao   [] = {"����������������������"};
const u8 PY_mb_te    [] = {"��"};
const u8 PY_mb_teng  [] = {"��������"};
const u8 PY_mb_ti    [] = {"������������������������������"};
const u8 PY_mb_tian  [] = {"����������������"};
const u8 PY_mb_tiao  [] = {"������������"};
const u8 PY_mb_tie   [] = {"������"};
const u8 PY_mb_ting  [] = {"ͣ��͡����ͤͥͦͧ͢"};
const u8 PY_mb_tong  [] = {"ͨͬͮͩͭͯͪͫͳͱͰͲʹ"};
const u8 PY_mb_tou   [] = {"͵ͷͶ͸"};
const u8 PY_mb_tu    [] = {"͹ͺͻͼͽͿ;��������"};
const u8 PY_mb_tuan  [] = {"����"};
const u8 PY_mb_tui   [] = {"������������"};
const u8 PY_mb_tun   [] = {"��������"};
const u8 PY_mb_tuo   [] = {"����������������������"};
const u8 PY_mb_w     [] = {"��������Σ"}; ///
const u8 PY_mb_wa    [] = {"��������������"};
const u8 PY_mb_wai   [] = {"����"};
const u8 PY_mb_wan   [] = {"����������������������������������"};
const u8 PY_mb_wang  [] = {"��������������������"};
const u8 PY_mb_wei   [] = {"Σ��΢ΡΪΤΧΥΦΨΩάΫΰαβγέίή��δλζηθξνιμεοκ"};
const u8 PY_mb_wen   [] = {"��������������������"};
const u8 PY_mb_weng  [] = {"������"};
const u8 PY_mb_wo    [] = {"������������������"};
const u8 PY_mb_wu    [] = {"����������������������������������������������������������"};
const u8 PY_mb_x     [] = {"ϦϺϳ��"}; ///
const u8 PY_mb_xi    [] = {"Ϧϫ����ϣ������Ϣ��Ϥϧϩ����ϬϡϪ��Ϩ����ϥϰϯϮϱϭϴϲϷϵϸ϶"};
const u8 PY_mb_xia   [] = {"ϺϹϻ��Ͽ��ϾϽϼ������"};
const u8 PY_mb_xian  [] = {"ϳ����������������������������������������������������"};
const u8 PY_mb_xiang [] = {"����������������������������������������"};
const u8 PY_mb_xiao  [] = {"����������������С��ТФ��ЧУЦХ"};
const u8 PY_mb_xie   [] = {"ЩШЪЫЭавбгЯЬдйкжмелиз"};
const u8 PY_mb_xin   [] = {"����о����п��н����"};
const u8 PY_mb_xing  [] = {"����������������������������"};
const u8 PY_mb_xiong [] = {"��������������"};
const u8 PY_mb_xiu   [] = {"��������������������"};
const u8 PY_mb_xu    [] = {"��������������������������������������"};
const u8 PY_mb_xuan  [] = {"������������ѡѢѤѣ"};
const u8 PY_mb_xue   [] = {"ѧѩѪ��ѥѦѨ"};
const u8 PY_mb_xun   [] = {"ѰѮѸѯѶѫѬѲѱѭѵѴѷѳ"};
const u8 PY_mb_y     [] = {"ѽ������Ҭ"}; ///
const u8 PY_mb_ya    [] = {"ѽѹ������ѾѺѻѼѿ������������"};
const u8 PY_mb_yan   [] = {"������������������������������������������������������������������"};
const u8 PY_mb_yang  [] = {"����������������������������������"};
const u8 PY_mb_yao   [] = {"��������ҢҦҤҥҡң��ҧҨҩҪҫԿ"};
const u8 PY_mb_ye    [] = {"ҬҭүҮҲұҰҵҶҷҳҹҴҺҸ"};
const u8 PY_mb_yi    [] = {"һ����ҽ��ҿҼҾ������������������������������������������������������������������������������������������"};
const u8 PY_mb_yin   [] = {"������������������������������ӡ"};
const u8 PY_mb_ying  [] = {"ӦӢӤӧӣӥӭӯӫӨөӪӬӮӱӰӳӲ"};
const u8 PY_mb_yo    [] = {"Ӵ"};
const u8 PY_mb_yong  [] = {"ӶӵӸӹӺӷ��ӽӾ��ӿ��Ӽӻ��"};
const u8 PY_mb_you   [] = {"����������������������������������������"};
const u8 PY_mb_yu    [] = {"����������������������������������������������������Ԧ����������ԡԤ������Ԣ��ԣ������ԥ"};
const u8 PY_mb_yuan  [] = {"ԩԧԨԪԱ԰ԫԭԲԬԮԵԴԳԯԶԷԹԺԸ"};
const u8 PY_mb_yue   [] = {"ԻԼ��������Ծ��Խ"};
const u8 PY_mb_yun   [] = {"������������������������"};
const u8 PY_mb_z     [] = {"������"}; ///
const u8 PY_mb_za    [] = {"������զ"};
const u8 PY_mb_zai   [] = {"����������������"};
const u8 PY_mb_zan   [] = {"��������"};
const u8 PY_mb_zang  [] = {"������"};
const u8 PY_mb_zao   [] = {"����������������������������"};
const u8 PY_mb_ze    [] = {"��������"};
const u8 PY_mb_zei   [] = {"��"};
const u8 PY_mb_zen   [] = {"��"};
const u8 PY_mb_zeng  [] = {"������"};
const u8 PY_mb_zha   [] = {"����������բագէթըե��"};
const u8 PY_mb_zhai  [] = {"իժլ��խծկ"};
const u8 PY_mb_zhan  [] = {"մձճղհնչյոշռսջվ��տպ"};
const u8 PY_mb_zhang [] = {"��������������������������������"};
const u8 PY_mb_zhao  [] = {"��������������������צ"};
const u8 PY_mb_zhe   [] = {"����������������������"};
const u8 PY_mb_zhen  [] = {"��������������������������������֡"};
const u8 PY_mb_zheng [] = {"��������������������֤֣��֢"};
const u8 PY_mb_zhi   [] = {"ְֱֲֳִֵֶַָֹֺֻּֽ֧֥֦֪֭֮֨֯֫֬֩��־������������ֿ������������������"};
const u8 PY_mb_zhong [] = {"����������������������"};
const u8 PY_mb_zhou  [] = {"����������������������������"};
const u8 PY_mb_zhu   [] = {"��סעף������������������������������������פ������"};
const u8 PY_mb_zhua  [] = {"ץ"};
const u8 PY_mb_zhuai [] = {"ק"};
const u8 PY_mb_zhuan [] = {"רשת׫׭"};
const u8 PY_mb_zhuang[] = {"ױׯ׮װ׳״��ײ"};
const u8 PY_mb_zhui  [] = {"׷׹׵׶׺׸"};
const u8 PY_mb_zhun  [] = {"׼׻"};
const u8 PY_mb_zhuo  [] = {"׿׾׽��������������"};
const u8 PY_mb_zi    [] = {"����������������������������"};
const u8 PY_mb_zong  [] = {"��������������"};
const u8 PY_mb_zou   [] = {"��������"};
const u8 PY_mb_zu    [] = {"����������������"};
const u8 PY_mb_zuan  [] = {"׬����"};
const u8 PY_mb_zui   [] = {"��������"};
const u8 PY_mb_zun   [] = {"����"};
const u8 PY_mb_zuo   [] = {"��������������"};





const T9PY_IDX Nult9py;
const T9PY_IDX t9PY_index[] =
{
	{"0", "0", PY_mb_space},
	{"*", "symbol", PY_mb_fuhao},	//ding add
	//{"2","A",PY_mb_a},
	{"2", "a", PY_mb_a},
	//{"2","B",PY_mb_space},
	{"2", "b", PY_mb_b},
	//{"2","C",PY_mb_space},
	{"2", "c", PY_mb_c},
	//{"3","D",PY_mb_space},
	{"3", "d", PY_mb_d},
	//{"3","E",PY_mb_e},
	{"3", "e", PY_mb_e},
	//{"3","F",PY_mb_space},
	{"3", "f", PY_mb_f},
	//{"4","G",PY_mb_space},
	{"4", "g", PY_mb_g},
	//{"4","H",PY_mb_space},
	{"4", "h", PY_mb_h},
	//{"4","I",PY_mb_space},
	//{"4","i",PY_mb_space},
	//{"5","J",PY_mb_space},
	{"5", "j", PY_mb_j},
	//{"5","K",PY_mb_space},
	{"5", "k", PY_mb_k},
	//{"5","L",PY_mb_space},
	{"5", "l", PY_mb_l},
	//{"6","M",PY_mb_space},
	{"6", "m", PY_mb_m},
	//{"6","N",PY_mb_space},
	{"6", "n", PY_mb_n},
	//{"6","O",PY_mb_o},
	{"6", "o", PY_mb_o},
	//{"7","P",PY_mb_space},
	{"7", "p", PY_mb_p},
	//{"7","Q",PY_mb_space},
	{"7", "q", PY_mb_q},
	//{"7","R",PY_mb_space},
	{"7", "r", PY_mb_r},
	//{"7","S",PY_mb_space},
	{"7", "s", PY_mb_s},
	//{"8","T",PY_mb_space},
	{"8", "t", PY_mb_t},
	//{"8","U",PY_mb_space},
	//{"8","u",PY_mb_space},
	//{"8","V",PY_mb_space},
	//{"8","v",PY_mb_space},
	//{"9","W",PY_mb_space},
	{"9", "w", PY_mb_w},
	//{"9","X",PY_mb_space},
	{"9", "x", PY_mb_x},
	//{"9","Y",PY_mb_space},
	{"9", "y", PY_mb_y},
	//{"9","Z",PY_mb_space},
	{"9", "z", PY_mb_z},
	{"24", "ai", PY_mb_ai},
	{"26", "an", PY_mb_an},
	{"26", "ao", PY_mb_ao},
	{"22", "ba", PY_mb_ba},
	{"24", "bi", PY_mb_bi},
	{"26", "bo", PY_mb_bo},
	{"28", "bu", PY_mb_bu},
	{"22", "ca", PY_mb_ca},
	{"23", "ce", PY_mb_ce},
	{"24", "ci", PY_mb_ci},
	{"28", "cu", PY_mb_cu},
	{"32", "da", PY_mb_da},
	{"33", "de", PY_mb_de},
	{"34", "di", PY_mb_di},
	{"38", "du", PY_mb_du},
	{"36", "en", PY_mb_en},
	{"37", "er", PY_mb_er},
	{"32", "fa", PY_mb_fa},
	{"36", "fo", PY_mb_fo},
	{"38", "fu", PY_mb_fu},
	{"42", "ha", PY_mb_ha},
	{"42", "ga", PY_mb_ga},
	{"43", "ge", PY_mb_ge},
	{"43", "he", PY_mb_he},
	{"48", "gu", PY_mb_gu},
	{"48", "hu", PY_mb_hu},
	{"54", "ji", PY_mb_ji},
	{"58", "ju", PY_mb_ju},
	{"52", "ka", PY_mb_ka},
	{"53", "ke", PY_mb_ke},
	{"58", "ku", PY_mb_ku},
	{"52", "la", PY_mb_la},
	{"53", "le", PY_mb_le},
	{"54", "li", PY_mb_li},
	{"58", "lu", PY_mb_lu},
	{"58", "lv", PY_mb_lv},
	{"62", "ma", PY_mb_ma},
	{"63", "me", PY_mb_me},
	{"64", "mi", PY_mb_mi},
	{"66", "mo", PY_mb_mo},
	{"68", "mu", PY_mb_mu},
	{"62", "na", PY_mb_na},
	{"63", "ne", PY_mb_ne},
	{"64", "ni", PY_mb_ni},
	{"68", "nu", PY_mb_nu},
	{"68", "nv", PY_mb_nv},
	{"68", "ou", PY_mb_ou},
	{"72", "pa", PY_mb_pa},
	{"74", "pi", PY_mb_pi},
	{"76", "po", PY_mb_po},
	{"78", "pu", PY_mb_pu},
	{"74", "qi", PY_mb_qi},
	{"78", "qu", PY_mb_qu},
	{"73", "re", PY_mb_re},
	{"74", "ri", PY_mb_ri},
	{"78", "ru", PY_mb_ru},
	{"72", "sa", PY_mb_sa},
	{"73", "se", PY_mb_se},
	{"74", "si", PY_mb_si},
	{"78", "su", PY_mb_su},
	{"82", "ta", PY_mb_ta},
	{"83", "te", PY_mb_te},
	{"84", "ti", PY_mb_ti},
	{"88", "tu", PY_mb_tu},
	{"92", "wa", PY_mb_wa},
	{"96", "wo", PY_mb_wo},
	{"98", "wu", PY_mb_wu},
	{"94", "xi", PY_mb_xi},
	{"98", "xu", PY_mb_xu},
	{"92", "ya", PY_mb_ya},
	{"93", "ye", PY_mb_ye},
	{"94", "yi", PY_mb_yi},
	{"96", "yo", PY_mb_yo},
	{"98", "yu", PY_mb_yu},
	{"92", "za", PY_mb_za},
	{"93", "ze", PY_mb_ze},
	{"94", "zi", PY_mb_zi},
	{"98", "zu", PY_mb_zu},
	{"264", "ang", PY_mb_ang},
	{"224", "bai", PY_mb_bai},
	{"226", "ban", PY_mb_ban},
	{"226", "bao", PY_mb_bao},
	{"234", "bei", PY_mb_bei},
	{"236", "ben", PY_mb_ben},
	{"243", "bie", PY_mb_bie},
	{"246", "bin", PY_mb_bin},
	{"224", "cai", PY_mb_cai},
	{"226", "can", PY_mb_can},
	{"226", "cao", PY_mb_cao},
	{"242", "cha", PY_mb_cha},
	{"243", "che", PY_mb_che},
	{"244", "chi", PY_mb_chi},
	{"248", "chu", PY_mb_chu},
	{"268", "cou", PY_mb_cou},
	{"284", "cui", PY_mb_cui},
	{"286", "cun", PY_mb_cun},
	{"286", "cuo", PY_mb_cuo},
	{"324", "dai", PY_mb_dai},
	{"326", "dan", PY_mb_dan},
	{"326", "dao", PY_mb_dao},
	{"343", "die", PY_mb_die},
	{"348", "diu", PY_mb_diu},
	{"368", "dou", PY_mb_dou},
	{"384", "dui", PY_mb_dui},
	{"386", "dun", PY_mb_dun},
	{"386", "duo", PY_mb_duo},
	{"326", "fan", PY_mb_fan},
	{"334", "fei", PY_mb_fei},
	{"336", "fen", PY_mb_fen},
	{"368", "fou", PY_mb_fou},
	{"424", "gai", PY_mb_gai},
	{"426", "gan", PY_mb_gan},
	{"426", "gao", PY_mb_gao},
	{"434", "gei", PY_mb_gei},
	{"436", "gen", PY_mb_gan},
	{"468", "gou", PY_mb_gou},
	{"482", "gua", PY_mb_gua},
	{"484", "gui", PY_mb_gui},
	{"486", "gun", PY_mb_gun},
	{"486", "guo", PY_mb_guo},
	{"424", "hai", PY_mb_hai},
	{"426", "han", PY_mb_han},
	{"426", "hao", PY_mb_hao},
	{"434", "hei", PY_mb_hei},
	{"436", "hen", PY_mb_hen},
	{"468", "hou", PY_mb_hou},
	{"482", "hua", PY_mb_hua},
	{"484", "hui", PY_mb_hui},
	{"486", "hun", PY_mb_hun},
	{"486", "huo", PY_mb_huo},
	{"542", "jia", PY_mb_jia},
	{"543", "jie", PY_mb_jie},
	{"546", "jin", PY_mb_jin},
	{"548", "jiu", PY_mb_jiu},
	{"583", "jue", PY_mb_jue},
	{"586", "jun", PY_mb_jun},
	{"524", "kai", PY_mb_kai},
	{"526", "kan", PY_mb_kan},
	{"526", "kao", PY_mb_kao},
	{"536", "ken", PY_mb_ken},
	{"568", "kou", PY_mb_kou},
	{"582", "kua", PY_mb_kua},
	{"584", "kui", PY_mb_kui},
	{"586", "kun", PY_mb_kun},
	{"586", "kuo", PY_mb_kuo},
	{"524", "lai", PY_mb_lai},
	{"526", "lan", PY_mb_lan},
	{"526", "lao", PY_mb_lao},
	{"534", "lei", PY_mb_lei},
	{"543", "lie", PY_mb_lie},
	{"546", "lin", PY_mb_lin},
	{"548", "liu", PY_mb_liu},
	{"568", "lou", PY_mb_lou},
	{"583", "lue", PY_mb_lue},
	{"586", "lun", PY_mb_lun},
	{"586", "luo", PY_mb_luo},
	{"624", "mai", PY_mb_mai},
	{"626", "man", PY_mb_man},
	{"626", "mao", PY_mb_mao},
	{"634", "mei", PY_mb_mei},
	{"636", "men", PY_mb_men},
	{"643", "mie", PY_mb_mie},
	{"646", "min", PY_mb_min},
	{"648", "miu", PY_mb_miu},
	{"668", "mou", PY_mb_mou},
	{"624", "nai", PY_mb_nai},
	{"626", "nan", PY_mb_nan},
	{"626", "nao", PY_mb_nao},
	{"634", "nei", PY_mb_nei},
	{"636", "nen", PY_mb_nen},
	{"643", "nie", PY_mb_nie},
	{"646", "nin", PY_mb_nin},
	{"648", "niu", PY_mb_niu},
	{"683", "nue", PY_mb_nue},
	{"686", "nuo", PY_mb_nuo},
	{"724", "pai", PY_mb_pai},
	{"726", "pan", PY_mb_pan},
	{"726", "pao", PY_mb_pao},
	{"734", "pei", PY_mb_pei},
	{"736", "pen", PY_mb_pen},
	{"743", "pie", PY_mb_pie},
	{"746", "pin", PY_mb_pin},
	{"768", "pou", PY_mb_pou},
	{"742", "qia", PY_mb_qia},
	{"743", "qie", PY_mb_qie},
	{"746", "qin", PY_mb_qin},
	{"748", "qiu", PY_mb_qiu},
	{"783", "que", PY_mb_que},
	{"786", "qun", PY_mb_qun},
	{"726", "ran", PY_mb_ran},
	{"726", "rao", PY_mb_rao},
	{"736", "ren", PY_mb_ren},
	{"768", "rou", PY_mb_rou},
	{"784", "rui", PY_mb_rui},
	{"786", "run", PY_mb_run},
	{"786", "ruo", PY_mb_ruo},
	{"724", "sai", PY_mb_sai},
	{"726", "sao", PY_mb_sao},
	{"726", "san", PY_mb_san},
	{"736", "sen", PY_mb_sen},
	{"742", "sha", PY_mb_sha},
	{"743", "she", PY_mb_she},
	{"744", "shi", PY_mb_shi},
	{"748", "shu", PY_mb_shu},
	{"768", "sou", PY_mb_sou},
	{"784", "sui", PY_mb_sui},
	{"786", "sun", PY_mb_sun},
	{"786", "suo", PY_mb_suo},
	{"824", "tai", PY_mb_tai},
	{"826", "tan", PY_mb_tan},
	{"826", "tao", PY_mb_tao},
	{"843", "tie", PY_mb_tie},
	{"868", "tou", PY_mb_tou},
	{"884", "tui", PY_mb_tui},
	{"886", "tun", PY_mb_tun},
	{"886", "tuo", PY_mb_tuo},
	{"924", "wai", PY_mb_wai},
	{"926", "wan", PY_mb_wan},
	{"934", "wei", PY_mb_wei},
	{"936", "wen", PY_mb_wen},
	{"942", "xia", PY_mb_xia},
	{"943", "xie", PY_mb_xie},
	{"946", "xin", PY_mb_xin},
	{"948", "xiu", PY_mb_xiu},
	{"983", "xue", PY_mb_xue},
	{"986", "xun", PY_mb_xun},
	{"926", "yan", PY_mb_yan},
	{"926", "yao", PY_mb_yao},
	{"946", "yin", PY_mb_yin},
	{"968", "you", PY_mb_you},
	{"983", "yue", PY_mb_yue},
	{"986", "yun", PY_mb_yun},
	{"924", "zai", PY_mb_zai},
	{"926", "zan", PY_mb_zan},
	{"926", "zao", PY_mb_zao},
	{"934", "zei", PY_mb_zei},
	{"936", "zen", PY_mb_zen},
	{"942", "zha", PY_mb_zha},
	{"943", "zhe", PY_mb_zhe},
	{"944", "zhi", PY_mb_zhi},
	{"948", "zhu", PY_mb_zhu},
	{"968", "zou", PY_mb_zou},
	{"984", "zui", PY_mb_zui},
	{"986", "zun", PY_mb_zun},
	{"986", "zuo", PY_mb_zuo},
	{"2264", "bang", PY_mb_bang},
	{"2364", "beng", PY_mb_beng},
	{"2426", "bian", PY_mb_bian},
	{"2426", "biao", PY_mb_biao},
	{"2464", "bing", PY_mb_bing},
	{"2264", "cang", PY_mb_cang},
	{"2364", "ceng", PY_mb_ceng},
	{"2424", "chai", PY_mb_chai},
	{"2426", "chan", PY_mb_chan},
	{"2426", "chao", PY_mb_chao},
	{"2436", "chen", PY_mb_chen},
	{"2468", "chou", PY_mb_chou},
	{"2484", "chuai", PY_mb_chuai},
	{"2484", "chui", PY_mb_chui},
	{"2484", "chun", PY_mb_chun},
	{"2486", "chuo", PY_mb_chuo},
	{"2664", "cong", PY_mb_cong},
	{"2826", "cuan", PY_mb_cuan},
	{"3264", "dang", PY_mb_dang},
	{"3364", "deng", PY_mb_deng},
	{"3426", "dian", PY_mb_dian},
	{"3426", "diao", PY_mb_diao},
	{"3464", "ding", PY_mb_ding},
	{"3664", "dong", PY_mb_dong},
	{"3826", "duan", PY_mb_duan},
	{"3264", "fang", PY_mb_fang},
	{"3364", "feng", PY_mb_feng},
	{"4264", "gang", PY_mb_gang},
	{"4364", "geng", PY_mb_geng},
	{"4664", "gong", PY_mb_gong},
	{"4824", "guai", PY_mb_guai},
	{"4826", "guan", PY_mb_guan},
	{"4264", "hang", PY_mb_hang},
	{"4364", "heng", PY_mb_heng},
	{"4664", "hong", PY_mb_hong},
	{"4823", "huai", PY_mb_huai},
	{"4826", "huan", PY_mb_huan},
	{"5426", "jian", PY_mb_jian},
	{"5426", "jiao", PY_mb_jiao},
	{"5464", "jing", PY_mb_jing},
	{"5826", "juan", PY_mb_juan},
	{"5264", "kang", PY_mb_kang},
	{"5364", "keng", PY_mb_keng},
	{"5664", "kong", PY_mb_kong},
	{"5824", "kuai", PY_mb_kuai},
	{"5826", "kuan", PY_mb_kuan},
	{"5264", "lang", PY_mb_lang},
	{"5366", "leng", PY_mb_leng},
	{"5426", "lian", PY_mb_lian},
	{"5426", "liao", PY_mb_liao},
	{"5464", "ling", PY_mb_ling},
	{"5664", "long", PY_mb_long},
	{"5826", "luan", PY_mb_luan},
	{"6264", "mang", PY_mb_mang},
	{"6364", "meng", PY_mb_meng},
	{"6426", "mian", PY_mb_mian},
	{"6426", "miao", PY_mb_miao},
	{"6464", "ming", PY_mb_ming},
	{"6264", "nang", PY_mb_nang},
	{"6364", "neng", PY_mb_neng},
	{"6426", "nian", PY_mb_nian},
	{"6426", "niao", PY_mb_niao},
	{"6464", "ning", PY_mb_ning},
	{"6664", "nong", PY_mb_nong},
	{"6826", "nuan", PY_mb_nuan},
	{"7264", "pang", PY_mb_pang},
	{"7364", "peng", PY_mb_peng},
	{"7426", "pian", PY_mb_pian},
	{"7426", "piao", PY_mb_piao},
	{"7464", "ping", PY_mb_ping},
	{"7426", "qian", PY_mb_qian},
	{"7426", "qiao", PY_mb_qiao},
	{"7464", "qing", PY_mb_qing},
	{"7826", "quan", PY_mb_quan},
	{"7264", "rang", PY_mb_rang},
	{"7364", "reng", PY_mb_reng},
	{"7664", "rong", PY_mb_rong},
	{"7826", "ruan", PY_mb_ruan},
	{"7264", "sang", PY_mb_sang},
	{"7364", "seng", PY_mb_seng},
	{"7424", "shai", PY_mb_shai},
	{"7426", "shan", PY_mb_shan},
	{"7426", "shao", PY_mb_shao},
	{"7436", "shen", PY_mb_shen},
	{"7468", "shou", PY_mb_shou},
	{"7482", "shua", PY_mb_shua},
	{"7484", "shui", PY_mb_shui},
	{"7486", "shun", PY_mb_shun},
	{"7486", "shuo", PY_mb_shuo},
	{"7664", "song", PY_mb_song},
	{"7826", "suan", PY_mb_suan},
	{"8264", "tang", PY_mb_tang},
	{"8364", "teng", PY_mb_teng},
	{"8426", "tian", PY_mb_tian},
	{"8426", "tiao", PY_mb_tiao},
	{"8464", "ting", PY_mb_ting},
	{"8664", "tong", PY_mb_tong},
	{"8826", "tuan", PY_mb_tuan},
	{"9264", "wang", PY_mb_wang},
	{"9364", "weng", PY_mb_weng},
	{"9426", "xian", PY_mb_xiao},
	{"9426", "xiao", PY_mb_xiao},
	{"9464", "xing", PY_mb_xing},
	{"9826", "xuan", PY_mb_xuan},
	{"9264", "yang", PY_mb_yang},
	{"9464", "ying", PY_mb_ying},
	{"9664", "yong", PY_mb_yong},
	{"9826", "yuan", PY_mb_yuan},
	{"9264", "zang", PY_mb_zang},
	{"9364", "zeng", PY_mb_zeng},
	{"9424", "zhai", PY_mb_zhai},
	{"9426", "zhan", PY_mb_zhan},
	{"9426", "zhao", PY_mb_zhao},
	{"9436", "zhen", PY_mb_zhen},
	{"9468", "zhou", PY_mb_zhou},
	{"9482", "zhua", PY_mb_zhua},
	{"9484", "zhui", PY_mb_zhui},
	{"9486", "zhun", PY_mb_zhun},
	{"9486", "zhuo", PY_mb_zhuo},
	{"9664", "zong", PY_mb_zong},
	{"9826", "zuan", PY_mb_zuan},
	{"24264", "chang", PY_mb_chang},
	{"24364", "cheng", PY_mb_cheng},
	{"24664", "chong", PY_mb_chong},
	{"24826", "chuan", PY_mb_chuan},
	{"48264", "guang", PY_mb_guang},
	{"48264", "huang", PY_mb_huang},
	{"54264", "jiang", PY_mb_jiang},
	{"54664", "jiong", PY_mb_jiong},
	{"58264", "kuang", PY_mb_kuang},
	{"54264", "liang", PY_mb_liang},
	{"64264", "niang", PY_mb_niang},
	{"74264", "qiang", PY_mb_qiang},
	{"74664", "qiong", PY_mb_qiong},
	{"74264", "shang", PY_mb_shang},
	{"74364", "sheng", PY_mb_sheng},
	{"74824", "shuai", PY_mb_shuai},
	{"74826", "shuan", PY_mb_shuan},
	{"94264", "xiang", PY_mb_xiang},
	{"94664", "xiong", PY_mb_xiong},
	{"94264", "zhang", PY_mb_zhang},
	{"94364", "zheng", PY_mb_zheng},
	{"94664", "zhong", PY_mb_zhong},
	{"94824", "zhuai", PY_mb_zhuai},
	{"94826", "zhuan", PY_mb_zhuan},
	{"248264", "chuang", PY_mb_chuang},
	{"748264", "shuang", PY_mb_shuang},
	{"948264", "zhuang", PY_mb_zhuang},
	{"", "", PY_mb_space},
	{NULL, NULL, NULL}	//ding  add
};





typedef struct
{
	const u8 *bh23456;
	const u8 *MB;
} T9BH_IDX;


typedef struct
{
	const u8 *HanZi;
	const u8 *MB;
} THanZiThink;



//  2  ������
//  3  ������
//  4  ����Ʋ
//  5  ������
//  6  ������
/*

const T9BH_IDX t9BH_index[] =
{
	{"2", "һ�����пɵ���Ҫ�ɹ�δ���ֲ�����������������"},
	{"22", "�����ڿ���ר��������������̩����ҷ���Ŀ��������������������������˰�"},
	{"222", "��̩����ҷ���Ŀ��������������������������˰�"},
	{"2223", "���������������������˰ҺĿ����޸����챯����������������"},
	{"22236", "��������"},
	{"22234", "�������Ÿ����������"},
	{"222346", "��"},
	{"222345", "���Ÿ�������"},
	{"2223456", "����"},
	{"2223453", "������"},
	{"2223454", "����"},
	{"2223455", "������"},
	{"2224", "�����������������̩��"},
	{"22242", "����"},
	{"22246", "���"},
	{"22245", "������̩��������"},
	{"222452", "����"},
	{"222456", "��̩"},
	{"222453", "����"},
	{"222454", "����"},
	{"226", "ר����ءʾ����ΤΥ������"},
	{"2262", "��"},
	{"2263", "ΤΥ�ۻ�����"},
	{"2264", "ʾյ�յ"},
	{"2265", "��ר��������"},
	{"223", "�ɰ������ʽ��δ���ֲ�����������������"},
	{"2232", "���������嶾���廷����������������õŪ������������ɪɺʽ��������������������׸������������������������������������������������������������������"},
	{"22322", "������������ɪ��������"},
	{"223226", "��������"},
	{"223223", "�����������������"},
	{"2232236", "��"},
	{"2232233", "�����������"},
	{"2232234", "��"},
	{"223224", "Ū�ﻷ������"},
	{"22326", "ʽ�ض���������袲���׸"},
	{"223262", "����"},
	{"223266", "�ض������"},
	{"223264", "����׸"},
	{"223265", "ʽ"},
	{"22323", "��������������������裵�����"},
	{"223232", "����������"},
	{"223236", "������������裵��"},
	{"2232362", "��������裵��"},
	{"2232363", "���"},
	{"2232364", "�����"},
	{"223233", "�"},
	{"223235", "��"},
	{"22324", "����õ������������̹���"},
	{"223242", "õ���"},
	{"223246", "�������������ɺ����"},
	{"2232464", "ɺ���������������۰�"},
	{"2232465", "���������"},
	{"223243", "����̹����"},
	{"223244", "��"},
	{"223245", "�������������"},
	{"22325", "�����������������"},
	{"2236", "������"},
	{"2233", "����߰������ج"},
	{"2234", "ĩδ��"},
	{"224", "����Ԫ����Ϲ������Զ������"},
	{"2246", "����ԪԶ��"},
	{"2243", "���������������ν�"},
	{"2245", "�������̹�������"},
	{"26", "�߶��Ŷ���򵽹�����ѱ���������������"},
	{"262", "�ѱ���������꣸����β������������Ҵ��ҿ�����������������߫��"},
	{"2622", "�޴�ҿ�����������������߫��󸧾ܿ��ٿ�����������������˺��ߦ�̰β�"},
	{"26226", "�����μ��Ҿ�������"},
	{"26223", "���̿��ҳ���ߢ���빰������"},
	{"262232", "���ҳ���ߢ��"},
	{"262236", "���޲������ⲫ߭"},
	{"262233", "�̴빰������˺��ߦ"},
	{"2622332", "�빰������˺��"},
	{"2622336", "ߦ"},
	{"2622333", "����"},
	{"2622334", "���"},
	{"26224", "�����ߺ��Ŷ��£"},
	{"262242", "���ߺ�"},
	{"262246", "�Ŷ��£"},
	{"262243", "��"},
	{"262245", "������ھ��̢��"},
	{"2622452", "����"},
	{"2622455", "̢��"},
	{"26225", "��߫��Ю"},
	{"262254", "��Ю"},
	{"2626", "�ľ�����ɨ̧�о�ͱЯ����̯��"},
	{"26262", "ɨŲ�������ݾ�ߨ����"},
	{"2626224", "Ų��"},
	{"262626", "��׫����"},
	{"262623", "Ť��"},
	{"262624", "�����ݾ�ߨ����"},
	{"2626242", "����"},
	{"2626246", "��"},
	{"2626243", "ߨ"},
	{"2626245", "����"},
	{"26266", "����������Ĵ��"},
	{"262666", "����"},
	{"262664", "����"},
	{"262665", "Ĵ��"},
	{"26263", "��׾��"},
	{"26264", "�Ȳ�������ִ�����Ƶ�����ֿ�"},
	{"262643", "����"},
	{"262645", "ִ���ȵ���������"},
	{"2626452", "��"},
	{"2626456", "����"},
	{"2626453", "����"},
	{"2626454", "ֿ�"},
	{"2626455", "��"},
	{"26265", "���ղ�ɦ��������ߡߪ����̧ͱ̯��"},
	{"262652", "��ߡߪ�ղ�"},
	{"2626526", "ߡߪ"},
	{"2626524", "�ղ�"},
	{"262656", "��������"},
	{"2626565", "����"},
	{"262653", "̧ͱ"},
	{"262654", "��̯��"},
	{"2626543", "̯��"},
	{"2623", "������׽��������Ҿ��Ͻ��۵�������ݵ���"},
	{"26232", "�ų����������°��"},
	{"262322", "ת����"},
	{"262326", "°����"},
	{"2623265", "��"},
	{"262323", "����������ԯ������"},
	{"2623232", "ԯ"},
	{"2623236", "�������������"},
	{"26232362", "�������"},
	{"26232364", "��"},
	{"2623233", "����"},
	{"26232466", "��"},
	{"26236", "��׽�ҳ����Ѻ��������"},
	{"262362", "�۵��ƺ�������Ѻ��Ҿ"},
	{"2623622", "����Ѻ��Ҿ������"},
	{"26236222", "������"},
	{"26236226", "ק"},
	{"26236223", "Ѻ��Ҿ"},
	{"26236224", "��"},
	{"2623626", "�ڹհ�"},
	{"26236232", "׽��������"},
	{"26236236", "����"},
	{"26236234", "��"},
	{"2623624", "��շ"},
	{"262366", "�"},
	{"262363", "�ڴ���ߧ"},
	{"262364", "��������"},
	{"262365", "����"},
	{"26233", "�����������"},
	{"262342", "���"},
	{"262346", "������"},
	{"262344", "ն��ǵ����"},
	{"262345", "����������"},
	{"26235", "�����ϵ��ӳ��Ͻ���"},
	{"2624", "죰绻��ʰ��������ӵִ���崷�����������ʰ��˩����ָߣ𺱧������������Я��ֿ�������起Ǥ��ҡ��ӵ������ߩ�����������ǰ����ֶ�����������������������ͦͶ��Ԯ����ִץ��������߬���������"},
	{"26242", "Ͷ�����ı������������촷��"},
	{"262422", "�촷��"},
	{"262426", "����"},
	{"262423", "Ǥ��ͦ���ܾ�"},
	{"262424", "��"},
	{"26246", "Ͷ������ָ�����쵷���ߣ�����ӵ��"},
	{"262462", "ӵ��"},
	{"262466", "Ͷ������"},
	{"262463", "ָ�������ߣ"},
	{"262464", "�����"},
	{"262465", "����"},
	{"26243", "����������Я����ߩ"},
	{"26244", "����۲�������������ץ��"},
	{"262442", "�۲�������������"},
	{"262446", "���"},
	{"262443", "ץ��"},
	{"26245", "��Ԯ����ҡ��ʰ��������˩���մ첥��"},
	{"262452", "ʰ����˩��"},
	{"262456", "����"},
	{"262454", "�մ첥��"},
	{"262455", "������Ԯ����ҡ"},
	{"2625", "�����������굧�බ�������Ӽ����ӿ���������§��šƲƴ����ˤ��̽����Ҵժ����ײ������������������ߤߥ"},
	{"26252", "��ˤ�������Ӹ�����������Ҵ"},
	{"262522", "��"},
	{"262526", "ˤ��"},
	{"262523", "�Ӹ�����"},
	{"262524", "����������Ҵ"},
	{"262525", "����ժײ����"},
	{"26256", "��š��̽��������"},
	{"26253", "�Ѹ�"},
	{"26254", "ƴ�����§����ߤ����"},
	{"262542", "ƴ"},
	{"262543", "��Ʋ"},
	{"262545", "��"},
	{"26255", "�����ؽ�����ߥ"},
	{"266", "��������аѻ�������"},
	{"2662", "��"},
	{"2664", "��ѻ���а����"},
	{"2665", "��"},
	{"263", "�ٸ���������������ת��ǵϽ���������ת"},
	{"2632", "��ǵϽ���������ת"},
	{"2636", "�Ͷ�"},
	{"264", "�Ż��ȽԱϱ���Ң�Ѹ�"},
	{"2642", "Ң����"},
	{"2646", "�ȽԱбϱ�"},
	{"2645", "�껮"},
	{"265", "���������ۤ߮��߮����ۤ��������߯�"},
	{"2652", "�����¾�����������ۤ"},
	{"2656", "߯"},
	{"2654", "�"},
	{"2655", "��"},
	{"23", "ʮ��������ȥ���身����Ѧ���Ԭ������������Ҽ�Ե�"},
	{"232", "��ʿ���ʳǷ⻵����ǽ����̳���Զ¹���ǽ"},
	{"2322", "�����˷⹡������ƺ��������̳��������ԫ��������������������������ܦܧܪܫ����"},
	{"23222", "̳������������������"},
	{"232226", "����"},
	{"2322264", "��"},
	{"2322265", "̳����������������"},
	{"23222656", "��"},
	{"23222654", "����������������������"},
	{"232226544", "����"},
	{"2322265444", "��"},
	{"23222654443", "��������"},
	{"23222654444", "������"},
	{"23222654445", "������"},
	{"23226", "��������"},
	{"23223", "�ҿ�ԫ��ܪ��ܧ������ܦ"},
	{"232232", "���Է����"},
	{"232236", "�ҿ�ԫ��ܪ��ܧ"},
	{"232233", "���������뿰��ܦ"},
	{"23224", "���������ܫ����"},
	{"232243", "���"},
	{"232244", "��ܫ"},
	{"232245", "����"},
	{"23225", "ƺǽ"},
	{"2326", "ؤ�����ٿ���ȴ��ؤܰ�������ع�������ȴ��ܣܥܯ���������갣������ȥ����ܤ"},
	{"23262", "����������ܤܣܥܯ"},
	{"23266", "������������"},
	{"23263", "����������ܰ��"},
	{"23264", "����"},
	{"23265", "ȥȴ������"},
	{"2323", "���߳��Ϲ���ϲԽ��ַ������������̹��ϲ����ַ�������������ܨ�����۳ܱ��������ܬ����������"},
	{"23232", "����۳��ԽȤ���Գ�������"},
	{"232322", "��۳����"},
	{"232326", "����"},
	{"232323", "ַ��"},
	{"2323242", "��"},
	{"2323245", "�߸�ԽȤ�������Գ�������"},
	{"23232452", "��ԽȤ��"},
	{"23232456", "����"},
	{"23232453", "������"},
	{"23232454", "�Գ�������"},
	{"23236", "����ϲ����ļ���ܱ����"},
	{"232362", "����ϲ����ļ���ܱ����"},
	{"2323622", "��̹���������ܬ���"},
	{"2323626", "��"},
	{"2323623", "Ԭ��������"},
	{"2323625", "ϲ����ļ���ܱ"},
	{"232363", "����ܨ"},
	{"232364", "����"},
	{"23233", "��"},
	{"23235", "��"},
	{"2324", "�඼�ѹ��ؿ�Т���ڶѹ���̮��Т����ܡ���������ƿ�����룲����»���������⹥���ջ��̽ؿ�������������������ܢܩ���������"},
	{"23246", "���ܡ"},
	{"232466", "Т���"},
	{"232463", "ܢ"},
	{"232464", "�ϳ࿲�º��������"},
	{"232465", "����̮��������"},
	{"23243", "��"},
	{"232436", "�߶�����ܩ����"},
	{"232433", "��"},
	{"232435", "�ѽ�"},
	{"232442", "���幸"},
	{"232446", "�������"},
	{"23245", "������"},
	{"2325", "�öշ��غ�������������������Ҽ�������ǿ���������ܭ�۲öշغ���־��ܮܲ�����"},
	{"23252", "����"},
	{"232523", "�պ���"},
	{"232524", "�ۿӷ������ܭ"},
	{"232525", "���ླ��"},
	{"23256", "־��Ҽ�������ܲ"},
	{"23254", "����"},
	{"23255", "����ܮ"},
	{"236", "��������������ټ�����껭���������������"},
	{"2362", "�����������������بت������"},
	{"23622", "�ݸ�ب�Ի��۱ϻ�"},
	{"236226", "���۱"},
	{"236223", "��ϻꦻ���"},
	{"2362235", "���ͷ�"},
	{"236224", "��"},
	{"23626", "�ٻ����ѳ���������������ت����"},
	{"23623", "���⻭�������������"},
	{"236232", "�ٻ���"},
	{"236236", "������ت��������"},
	{"2362365423", "ت����"},
	{"236233", "��"},
	{"236234", "�����������"},
	{"236235", "�����"},
	{"23624", "��"},
	{"23625", "����������"},
	{"2362542", "����������"},
	{"2362542��", "����������"},
	{"2363", "�����縲����ƮƱ��������Ҫ������۲ư"},
	{"23632", "��"},
	{"23636", "��"},
	{"236332", "ҪƱ����������Ʈư�縲۲"},
	{"23634", "��̼�"},
	{"23635", "��"},
	{"2364", "����괼�׷Ӻ��Ϳ�����ø������ȩ����̪ͪ��Э������������������������������������������������������������������������"},
	{"236462", "���������ͺ�����������ȩ��̪����������"},
	{"2364622", "����ͪ����������ø��������"},
	{"23646222", "����"},
	{"236462226", "����"},
	{"236462223", "�ͺ�����������ȩ"},
	{"236462224", "��̪"},
	{"23646226", "����������"},
	{"23646223", "��ͪ����������"},
	{"236462242", "ø��������"},
	{"236462246", "��������"},
	{"236462243", "����"},
	{"236462245", "��������"},
	{"23646225", "����������������"},
	{"2364625", "��"},
	{"23645", "������"},
	{"2365", "֧�������۪�����"},
	{"2365365", "��۪���"},
	{"233", "���̹���������ȡ��ֱ�ٴϵ��Ƽ���ƸɢЬְ"},
	{"2332", "إ�سܳ��´ϵ����ʸ﹢���������ƻ��Լ�������Ͼۿ�����������������çïĳ����źƸƻ��"},
	{"23322", "��ĳְ��Ƹ��ź������"},
	{"233222", "��ȡ�����Ĺ�ְ��Ȣ��"},
	{"2332222", "������������˹�ۿ������"},
	{"2332226", "ȡ��ҮȢ���۸����"},
	{"2332223", "ĳְ��Ƹ��ź������"},
	{"2332224", "��"},
	{"23322246", "��"},
	{"23322245", "����������˹�ۿ��������"},
	{"2332225", "����������"},
	{"233226", "��ܿ��έ��"},
	{"233223", "��ݼ"},
	{"233224", "ܽ��ܾ��"},
	{"23326", "������������"},
	{"233266", "ѿ"},
	{"233263", "��"},
	{"233264", "��������"},
	{"233232", "ܶ��ݨ����������޷"},
	{"233236", "������۴����ަ"},
	{"2332362", "��Ь��ޥ����������������պ�"},
	{"23323622", "������"},
	{"233236223", "������"},
	{"2332362234", "�ƽ�ѥ���ϱ�����"},
	{"2332362235", "�ΰ�"},
	{"2332362242", "ɢ"},
	{"2332362246", "ȵ"},
	{"23323626", "��"},
	{"23323623", "��"},
	{"23323624", "��"},
	{"2332363", "��ަ"},
	{"2332364", "��պ�"},
	{"2332365", "��"},
	{"233233", "������ݽ��"},
	{"233234", "��ݾ��ݿ"},
	{"233235", "ݩ"},
	{"233242", "����"},
	{"233246", "ï����������ޯި"},
	{"233243", "�����������"},
	{"233244", "��"},
	{"233245", "���﹧ç��ާ"},
	{"23325", "ƻ����Ǿ޽ާ޸"},
	{"2336", "�ճ����߹�ꪹ�����ҩ�洣�ź���������̦����ֱ��ݦ��ɰž���Ǭ��ܻܺ����ݻ����������������޵��é��ܼܵޤ�߹ʿ���ε����ҩ������������ݡݢݣݤݥݧ��������޶"},
	{"23362", "�ſ�����𳾤ε޵ݣ��ݢ��ܻܺ�������"},
	{"233622", "ֱ�溫Ǭ���ߴ���ݡ��"},
	{"2336226", "ݢ"},
	{"2336223", "���"},
	{"233626", "ܻܺ����"},
	{"233623", "��������"},
	{"233624", "������𳾤ε޵ݣ��"},
	{"233625", "��"},
	{"233662", "ҩ����ݥݻݧݦ����"},
	{"233664", "ܼܸܵ"},
	{"233665", "��"},
	{"23363", "�ڰ���������"},
	{"23364", "��ܴܹ����������޶"},
	{"23365", "�Ͼ�é�ӿ���̦ݤޤ��"},
	{"2333", "�ݴ��Ƹ�����Ļ��Ӣ�ƾ�������Ĺĺɻ����������������������������ޫ���ٸ�ġ������ް�ݴ�Ļļ��������ĪĽȧӢ��ݪݫ��������ީު޾"},
	{"23332", "��ɻ������޾"},
	{"23336", "���ھ�Ӣ����������������������ޫް"},
	{"233362", "ݪĪĻĽļĹġ��ĺ����ު��ީ"},
	{"2333622", "��ީ"},
	{"23336222", "ĪĻĽļĹġ��ĺ"},
	{"23336223", "����ު"},
	{"23336224", "�ȸ�"},
	{"2333623", "�����������"},
	{"23336236", "����ݫ����ȧ"},
	{"23336233", "��"},
	{"2333624", "Ӣ����"},
	{"233363", "��������������ޫް"},
	{"233364", "������"},
	{"23333", "��"},
	{"23335", "����"},
	{"2334", "�зҺɻ����������϶�������ή������������ݰݲݳݴ��������ެ���ͲԺɻ���������Է����ܴ����������޿������Ѧܷ��������޺����ݬ���˲̲�л񽶾�����������ܸܹ��������������������ݭݮݯݱݵݶ������������ޱ޹޼������"},
	{"23342", "��ܷݬ����޹޼��ݭݮ����ή"},
	{"233426", "��ݭݮ��"},
	{"233423", "ܷݬ����޹޼"},
	{"233424", "��ή"},
	{"23346", "������������������������޺������"},
	{"233466", "�ϰ�"},
	{"233463", "����������޺������"},
	{"233464", "�������ѻ�ݵݶ������"},
	{"233465", "������Է�����"},
	{"23343", "��ݰ����ݯ���������"},
	{"233432", "���������ޮ"},
	{"233436", "�ɱ���Ѧ��"},
	{"233433", "ݯ��"},
	{"233434", "����"},
	{"233435", "ݰ���Ƚ���"},
	{"23344", "������ޱ޿"},
	{"23345", "��������ݱݲ��������"},
	{"233456", "�Է���"},
	{"233454", "�ʽ�ެ"},
	{"233455", "���߲�ݳݴ��"},
	{"2335", "������Ƽ�ٻ�Ƽн������ݷ��ޭ����«ɯ�ϱ��β��Ķ�����������оӨөӫ����֥������ݹ����������������ޡޢ޲޴޻�"},
	{"23352", "â����������޳"},
	{"233523", "��������޻"},
	{"233524", "����������������Ģ��"},
	{"233525", "ݷ�е���н޲"},
	{"23356", "��Ӫө«����Ө��֥о"},
	{"233562", "«����Ө��ݹ"},
	{"233566", "��������"},
	{"233563", "Ӫө��"},
	{"233564", "��ݺ��"},
	{"233565", "֥оӫ��"},
	{"23353", "��"},
	{"23354", "���Ͻ��Ѷ��������޴"},
	{"233542", "���Ͻ��Ѷ��������޴"},
	{"233543", "ޭ��"},
	{"23355", "���������巪��ݸ��������"},
	{"233552", "����Ƽ��ޡ����ɯã��"},
	{"2335526", "������"},
	{"2335523", "��ɯ��"},
	{"2335524", "���巪"},
	{"2335525", "ã��"},
	{"233556", "��ݸ����������ޣޢ"},
	{"234", "ľ������������������������������"},
	{"2345", "¥����������ж��¸�������������"},
	{"23452", "��֦�±������౭����ģ"},
	{"234522", "������Ш��"},
	{"2345226", "��ջ��"},
	{"2345223", "����"},
	{"2345224", "е"},
	{"234526", "���Ĺ������俬"},
	{"234523", "�����������ɿ���ֲ�"},
	{"2345232", "�Ź�ܽ������������"},
	{"2345236", "֦�±������๣��鬲�"},
	{"2345233", "�������ֲ骸���"},
	{"23452332", "����Ҭ��Ⱥ�"},
	{"23452336", "����ֲ�"},
	{"23452333", "ģ"},
	{"23452335", "����"},
	{"2345234", "�ֽ�ɭ�����������"},
	{"23452345", "�ֳ�����ɭ����´"},
	{"234523452", "��ɭ"},
	{"234523456", "������"},
	{"234523453", "�"},
	{"234523454", "�������"},
	{"2345235", "��"},
	{"234524", "�����౭�������"},
	{"2345246", "�����"},
	{"2345243", "������"},
	{"2345244", "��"},
	{"2345245", "��������"},
	{"234525", "������"},
	{"23456", "��Ȩ�������������Ͱ"},
	{"234562", "轸�����駸�������"},
	{"234566", "���������"},
	{"234563", "�����"},
	{"234564", "��"},
	{"234565", "Ȩ���������Ͱ������"},
	{"2345654", "��"},
	{"23453", "������뵵��������"},
	{"234532", "��������"},
	{"234536", "������魼�ӣ����������ͩ���"},
	{"2345362", "��ͩ��������"},
	{"23453622", "�����������ù���"},
	{"23453623", "��ͩ�"},
	{"23453624", "��"},
	{"2345363", "�����"},
	{"23453633", "���"},
	{"2345364", "����魼�ӣ"},
	{"234534", "��"},
	{"234535", "�ӵ�������"},
	{"23454", "ǹ�ɻ�������������"},
	{"234542", "������÷�������ö���������"},
	{"2345426", "÷��"},
	{"2345423", "���������"},
	{"2345424", "��ö"},
	{"234546", "��輸����ݹ�������"},
	{"2345462", "����Φ���"},
	{"2345466", "�ݹ�"},
	{"2345463", "������"},
	{"2345464", "դ��������"},
	{"2345465", "輸���"},
	{"234543", "���׵�������޻����ϭ"},
	{"2345436", "���޻����ϭ"},
	{"2345434", "��"},
	{"2345435", "׵���"},
	{"234544", "���������ɼ��"},
	{"2345446", "��"},
	{"2345443", "��"},
	{"2345444", "ɼ"},
	{"234545", "ǹ������˨�����ȷ���������"},
	{"2345456", "ǹ��"},
	{"2345454", "�ȷ�����"},
	{"2345455", "��������"},
	{"23455", "�����������¥��������"},
	{"234552", "��׮����У�����������������"},
	{"2345526", "����"},
	{"2345523", "����������̴"},
	{"2345524", "׮����У"},
	{"2345525", "�������"},
	{"234556", "��������ȶ��"},
	{"234553", "�"},
	{"234554", "�������¥��"},
	{"234555", "�����������޹����ե�"},
	{"2345556", "���������޹����ե"},
	{"2345554", "�"},
	{"2345555", "��"},
	{"235", "�²����������"},
	{"2352", "�����������ɥ��"},
	{"2356", "�������"},
	{"2354", "ɥ��"},
	{"2355", "��"},
	{"24", "�ٴ��˻��ҳ�������������ҽ�������贽����������"},
	{"242", "��������������ҽ�������贽��ҽ����������"},
	{"2426", "��������"},
	{"2423", "��ѹ�����˳�����"},
	{"2424", "����������������"},
	{"246", "����أ��ƥ��������ʢ�������Ͼ�갾��ʢ��۽"},
	{"24652", "��ֳ��"},
	{"24656", "���д���"},
	{"24653", "����������"},
	{"24654", "�����������ѳ��������"},
	{"24655", "����"},
	{"243", "���������ʯ��ҳ��آ���������ݲ�������"},
	{"2432", "������"},
	{"24323", "��"},
	{"2436", "����������ȷ���аٲ��������������������ʯˣ�������������������������������������������������������������ٱ�����������ȷ���������������ܿ���ɰ���������ڰ��ôŵ�����Ǽ����µ������˶̼����ҳӲש���������������������������������������"},
	{"24362", "��˶���������ש���������ذ���"},
	{"243622", "�����ש���������ع����ĵ����˻�������"},
	{"2436226", "��������������"},
	{"2436223", "������Ӳ����"},
	{"24362236", "Ӳ����"},
	{"24362233", "�����˻�������"},
	{"2436224", "��˶����"},
	{"2436225", "����"},
	{"243626", "��µ���봡�������ò�����"},
	{"2436266", "�����ò�"},
	{"2436263", "��"},
	{"2436264", "��"},
	{"2436265", "������"},
	{"243623", "��ɰ�����ϵ���̼����"},
	{"243624", "ȷ�������ҷ�����������"},
	{"2436246", "��������������"},
	{"24362462", "�������������"},
	{"24362466", "����"},
	{"24362464", "ȷ����"},
	{"24362465", "��������"},
	{"2436243", "�����Խ�"},
	{"2436244", "��"},
	{"2436245", "������"},
	{"243625", "������������ڰ�������"},
	{"2436256", "�ܴ�����������������"},
	{"2436254", "��������"},
	{"2436255", "����������"},
	{"24366", "��"},
	{"24363", "�����Ͷ���ˣ���"},
	{"243636", "��"},
	{"243633", "������ˣ���"},
	{"2436332", "����"},
	{"2436336", "ˣ"},
	{"2436334", "�"},
	{"2436335", "��"},
	{"243645", "ҳ��"},
	{"2433", "ئ"},
	{"2435", "������اث������"},
	{"24352", "ا"},
	{"243526", "��"},
	{"243523", "��"},
	{"24356", "ث"},
	{"24353", "���"},
	{"24355", "��"},
	{"244", "����ԭԸ����"},
	{"244236", "��"},
	{"24465", "����"},
	{"2443", "ԭԸ��"},
	{"24436", "ԭԸ"},
	{"24434", "����"},
	{"2445", "����"},
	{"245", "���ɴ�������̫̬����������ǿ��汼�����������������"},
	{"2452", "���������������������������������"},
	{"24522", "���������"},
	{"245265", "��"},
	{"24523", "���汼���������"},
	{"2452456", "��"},
	{"2456", "��Ÿ��ŷŹ���"},
	{"24562", "�"},
	{"24564", "����ŹŷŸ"},
	{"2453", "������"},
	{"24536", "�ٷ���"},
	{"2454", "�ҿ�ˬ������"},
	{"24542", "����"},
	{"24543", "��"},
	{"24544", "�ҿ�"},
	{"24545", "��"},
	{"245454", "ˬ"},
	{"2455", "Ȯ̫��ǣ��̬�"},
	{"24552", "�"},
	{"24556", "��ǣ"},
	{"24555", "̬"},
	{"25", "��ƽ���ۣ��ջ�����ϼ��ѩ������¶��˪����������������"},
	{"256", "��¶��˪���������������ұ������������������¶˪��ѩ"},
	{"2562", "��"},
	{"25624", "��"},
	{"2563", "����������¶ù����˪��ϼ����ѩ��۹�������������������������"},
	{"25635", "����������˪�����"},
	{"256355", "ѩϼ��"},
	{"2563555", "������۹¶"},
	{"25635555", "ù�������޻�����"},
	{"256355555", "������������"},
	{"2565", "�Ա�߯"},
	{"25655", "߯"},
	{"254", "�м���ۣ��ƽۣ�м�����"},
	{"2542", "����ƽۣ���"},
	{"25423", "ƽ"},
	{"254234", "����"},
	{"254245", "��ۣ��"},
	{"2544", "��"},
	{"6", "����Ҳ�Գ�������6С��ǿ���������������쵼������ں�����"},
	{"62", "������ǿȺ˾��ο�����Ƚ�������¼��Ѱ����"},
	{"622", "�����Ƚ�������¼��Ѱ������"},
	{"6222", "Ѱ����"},
	{"62226", "Ѱ��"},
	{"6226", "�߰������ȿѿ���¼������"},
	{"62264", "�޼��˿Ѽȿ���"},
	{"6223", "����"},
	{"62234", "��"},
	{"6224", "��������Ⱥ"},
	{"62246", "��"},
	{"62243", "����Ⱥ"},
	{"6225", "������"},
	{"62256", "��"},
	{"62254", "��"},
	{"626", "�����ѵ��Ѹ�ǿ���������������쵼������ں�����"},
	{"6262", "�����������쵼"},
	{"62626", "��"},
	{"626264", "��"},
	{"626265", "��"},
	{"626232", "��"},
	{"626233", "������"},
	{"6266", "����ں�����"},
	{"62662", "����"},
	{"62665", "��"},
	{"626652", "��"},
	{"6263", "����ǿ"},
	{"62636", "ǿ��"},
	{"6264", "�������Ѹ�����"},
	{"62642", "�Ÿ�"},
	{"62646", "��"},
	{"62643", "������"},
	{"62644", "��"},
	{"6265", "������������"},
	{"62652", "����"},
	{"62656", "��"},
	{"62654", "�൯��"},
	{"623", "˾��Һ�Ѹ��"},
	{"6232", "����"},
	{"6236", "˾"},
	{"6233", "�Һ�"},
	{"6233222", "�Һ�"},
	{"6235", "Ѹ"},
	{"624", "��پ��Ӿ־�����βοʬ����ξ��չ�پ���"},
	{"6242", "��ƨ������ξο��չ�ٲ�Ӿ�"},
	{"62422", "��ξο��"},
	{"62426", "ƨ��"},
	{"62423", "������չ�����"},
	{"6246", "����������"},
	{"62466", "����"},
	{"62463", "������"},
	{"624645", "��"},
	{"6243", "�ٱ۱ܽ���ƩˢϬм����������"},
	{"62436", "��ٱڱ�ˢ�����Ʃ��������"},
	{"624362", "��ٱڱܱ����Ʃ����"},
	{"6243625", "�ٱڱܱ����Ʃ����"},
	{"62436252", "����"},
	{"624363", "ˢ"},
	{"62435", "Ϭм"},
	{"624354", "м"},
	{"6244", "������β��������"},
	{"62442", "β"},
	{"62446", "��"},
	{"62443", "��"},
	{"62444", "��������"},
	{"6245", "�ڱܳٳ߾�����ʺ����"},
	{"62452", "����ʺ����������"},
	{"62453", "����"},
	{"62454", "��ʺ����"},
	{"62455", "�پ�"},
	{"624555", "��"},
	{"66", "��ؿ�и���ᾭ�����ຢ������ϸԼֽ��"},
	{"662", "�����ຢ������ϸԼֽ���ݰ�д��켨����������"},
	{"6622", "��и���������������γ���������������������������������������"},
	{"66222", "��γ��"},
	{"662223", "��"},
	{"662224", "�߰���"},
	{"66226", "����������������"},
	{"66223", "��������"},
	{"662236", "��箸���������"},
	{"662233", "�����������"},
	{"662234", "�"},
	{"662242", "�ȼ�����������"},
	{"662246", "�"},
	{"662243", "��"},
	{"662245", "����������"},
	{"66225", "��"},
	{"6626", "�ۼ;�������Ŧɧ����ѷԵ��Ŧ����������"},
	{"66262", "����Ŧ�����"},
	{"66266", "Ե�����"},
	{"66263", "�����"},
	{"66264", "��������ѷ"},
	{"66265", "Ԧ"},
	{"662652", "���侭�����"},
	{"662656", "�׺"},
	{"662653", "���"},
	{"662654", "��"},
	{"662655", "ɧ"},
	{"6623", "�Ҵ¸ٹἩ����������ɴ����ʻϸӧ֯��������������������������������"},
	{"66232", "�����"},
	{"662323", "��"},
	{"66236", "�������翸�����ӧ������"},
	{"662362", "�ϸ������������������"},
	{"6623622", "����"},
	{"6623623", "ϸ������������������"},
	{"6623624", "ʻ֯"},
	{"662363", "������"},
	{"662364", "������ӧ"},
	{"662336", "����"},
	{"662334", "��"},
	{"662345", "ɴ"},
	{"662354", "��"},
	{"6624", "�������з׷���»��漶���ɾԾ�������������ά����Ѥѱ��Լֽ�����������������������������������������"},
	{"66242", "������ν�����"},
	{"662426", "��"},
	{"662423", "������"},
	{"662424", "�ν�"},
	{"662462", "ֽ����������߾���Ѥ���"},
	{"662466", "����߾�"},
	{"662463", "��Ѥ"},
	{"662464", "���"},
	{"662465", "Լ��������縷���"},
	{"662432", "������ά����������"},
	{"662436", "��������ѱ��"},
	{"662433", "ѱ"},
	{"662434", "��"},
	{"662435", "ά��"},
	{"662446", "���"},
	{"662443", "�"},
	{"66245", "�����ڲ����绺�"},
	{"662456", "��"},
	{"662454", "�ڲ���"},
	{"662455", "�绺�"},
	{"6625", "������޷ĺ����̽�¿��ƭ����ͳ��������פ�������������������������"},
	{"66252", "פ�����ƽʲ�������ͳ����"},
	{"662526", "��ͳ����"},
	{"662523", "����"},
	{"662524", "���ƽʲ�"},
	{"662525", "��"},
	{"66256", "¿��ƭ��"},
	{"662564", "��"},
	{"66254", "��������̼������������"},
	{"662542", "��"},
	{"6625423", "������"},
	{"6625424", "��"},
	{"662546", "�"},
	{"662543", "��"},
	{"662545", "��"},
	{"66255", "�����������"},
	{"666", "˿����Ѳة�����������"},
	{"6662", "˿�"},
	{"66624", "��"},
	{"66662", "˿�"},
	{"66636", "�����޽���"},
	{"66645", "ة��"},
	{"66656", "Ѳ"},
	{"66654", "ӯ"},
	{"66", "���Ͽ������ߺ���ѷ����"},
	{"663", "ؽ��"},
	{"6636", "ؽ"},
	{"6635", "��"},
	{"664", "ˮ������������"},
	{"6646", "�����"},
	{"66464", "��"},
	{"66465", "�"},
	{"6643", "ؾ"},
	{"6644", "��"},
	{"6645", "��ˮ������"},
	{"66456", "��"},
	{"664563", "��"},
	{"66453", "��"},
	{"665", "����������ĸ������"},
	{"6652", "��ĸ���"},
	{"66525", "ĸ���"},
	{"6656", "����"},
	{"66566", "��"},
	{"66564", "����"},
	{"665645", "��"},
	{"66565", "��"},
	{"63", "�ճ¶��ް�½����������"},
	{"632", "�������ͼ�½üİ����������"},
	{"6322", "������������"},
	{"6326", "�Ͱ������"},
	{"6323", "��������ª�����"},
	{"63232", "������"},
	{"63236", "��ª���"},
	{"6324", "�������������¤üİ����������"},
	{"63242", "������"},
	{"632423", "����"},
	{"63246", "��¤"},
	{"63243", "İü������"},
	{"63245", "�⵰��"},
	{"632453", "�㵰"},
	{"6325", "����"},
	{"63254", "��"},
	{"636", "Ҳ������"},
	{"6362", "��"},
	{"6364", "��"},
	{"6365", "��"},
	{"633", "��������϶�������������������"},
	{"6332", "���������"},
	{"63323", "������"},
	{"6336", "��϶�����������������"},
	{"63362", "��������������"},
	{"63363", "������"},
	{"6335", "϶"},
	{"634", "��������¡��������"},
	{"6342", "��������������"},
	{"63422", "��"},
	{"63423", "����"},
	{"63424", "��"},
	{"6346", "����¡����������"},
	{"6343", "������������"},
	{"6344", "��"},
	{"6345", "׹���ս׳�"},
	{"635", "����������Ժ����"},
	{"6352", "��������"},
	{"6354", "����"},
	{"6355", "Ժ��"},
	{"64", "С��ü�Ů��������������"},
	{"642", "Ů�ն𸾹ü�����Ŭ����"},
	{"6422", "�˼�ý�������̹�������������"},
	{"64222", "������������"},
	{"64226", "������"},
	{"64223", "��������"},
	{"642236", "������"},
	{"642233", "ý櫹ü���"},
	{"642235", "��"},
	{"642242", "��"},
	{"642245", "��"},
	{"64225", "��"},
	{"6426", "��ķ������ūʼ����������ʼ������������������������Ŭķūŭ���"},
	{"64262", "����������"},
	{"64266", "������ķ"},
	{"64263", "���������"},
	{"64264", "���"},
	{"642645", "��"},
	{"64265", "ūŬ�������ʼ�����ŭ"},
	{"642656", "Ŭ�������"},
	{"642653", "ʼ����"},
	{"642654", "�"},
	{"642655", "ŭ"},
	{"6423", "����ˡ�������Ͻ�����������������ˡ���������"},
	{"64236", "���派�泽��������"},
	{"642362", "�������������ˡ"},
	{"6423626", "��"},
	{"6423623", "�派����"},
	{"6423624", "��"},
	{"6423625", "ˡ"},
	{"64234", "��"},
	{"64235", "��"},
	{"6424", "�齿��ɩϱҦ�澻����������ǽ��梶�ɩϱ��Ҧ�������"},
	{"64242", "��歶�������"},
	{"64246", "��������"},
	{"64243", "ɩ�ϱ��"},
	{"64245", "Ҧ�����"},
	{"6425", "�նʷ����������������õ��ӷ�����������Ѷ�淼��������������"},
	{"64252", "����毼����ѵ���"},
	{"64256", "���"},
	{"64253", "�"},
	{"64254", "�����"},
	{"64255", "���������"},
	{"646", "��������"},
	{"6464", "��"},
	{"6465", "��"},
	{"643", "�ؼӼܼ�Ƥ��������ʭؾۿ������"},
	{"6436", "������긼���������ʭ"},
	{"64362", "��긼���ʭ"},
	{"643626", "����ۿ"},
	{"643623", "ʭ��"},
	{"643625", "������"},
	{"64365", "Ƥ��"},
	{"644", "���î��"},
	{"6445", "��"},
	{"645", "С������ʡȸ�����з�"},
	{"6456", "��"},
	{"6454", "ظ"},
	{"6455", "Ϊ"},
	{"64556", "��"},
	{"65", "�����ܵ�ͨ��ϰ��˫������"},
	{"652", "ϰϷ�δ����ʥ�𾢾�"},
	{"6526", "����Ϸ����¾����"},
	{"65264", "Ϸ"},
	{"65265", "����������ҵ�����"},
	{"652652", "�����������¾��"},
	{"652655", "��"},
	{"6523", "ʥ���������Ͼ���"},
	{"65232", "ʥ���ɾ�����"},
	{"652322", "��"},
	{"652326", "��"},
	{"652323", "��"},
	{"652325", "����"},
	{"6524", "�����������Ͳ�"},
	{"65243", "��"},
	{"65245", "�������"},
	{"656", "ȰԤԥ������ɣ��������ì������������������"},
	{"6562", "��"},
	{"6566", "��Ԥì��ԥ�����������"},
	{"65662", "Ԥ"},
	{"65664", "ì�����ԥ�����������"},
	{"656642", "��"},
	{"656646", "ԥ"},
	{"656643", "���"},
	{"656644", "�����������"},
	{"6563", "��"},
	{"6564", "Ȱ"},
	{"65644", "��"},
	{"6565", "˫��ɣ��"},
	{"65656", "��ɣ�"},
	{"656565", "��"},
	{"653", "ͨ�ܵ���̨ۢ������ۢ�"},
	{"6536", "����̨����ۢ��µ�ͨ����"},
	{"65362", "̨�ʵ���ۢ����ͨ������"},
	{"653622", "���ͨ������"},
	{"653626", "ۢ"},
	{"653625", "�ʵ���"},
	{"65364", "��"},
	{"654", "�ǻ���Ĳ���ʵʹ���"},
	{"6542", "Ĳ��"},
	{"654224", "��"},
	{"6546", "�ʻ���"},
	{"65464", "��"},
	{"65465", "��"},
	{"6543", "��"},
	{"6544", "��ǵ�"},
	{"6545", "����������������"},
	{"65454", "��Ǽ�������"},
	{"65455", "��Ǽ���"},
	{"655", "������"},
	{"6552", "��"},
	{"6553", "��"},
	{"3", "�й�����ͬ���������ʱֻ�ݱ���ռ¬ҵ����������ټ���ٹ�˧ʦ�Ӽ⳾ʡ��ȸ����Ф�ֳ��������ǹǺ�����"},
	{"32", "��ս�����˵��Ƶ͹��"},
	{"322", "�ϱ�������ۺ�����"},
	{"3222", "�Ǿ�쳱�����������"},
	{"32223222", "�Ǿ�쳱�������"},
	{"3226", "����"},
	{"3223", "����"},
	{"32235", "��"},
	{"3224", "��������"},
	{"32246", "��������"},
	{"3225", "��"},
	{"326", "귻�¬­²��Ű�����������"},
	{"3262", "¬�­"},
	{"3264", "򮻢²�Ǳ���Ű�������"},
	{"3265", "�"},
	{"323", "����Щֹ׿����������"},
	{"3232", "�����Щ��ƴ˿���Ƶ��ȣֹ�����������������������������"},
	{"32322", "������"},
	{"323223", "����"},
	{"32323", "����Ƶ�"},
	{"32324", "��Щ��������������"},
	{"323245", "��������������������ȣ"},
	{"3236", "׿��ս±ռ����������͹����������"},
	{"32362", "׿��ս��±���������"},
	{"323626", "������"},
	{"323623", "��"},
	{"323625", "��"},
	{"32366", "��"},
	{"32364", "��±��"},
	{"324", "���������ٲ���"},
	{"3246", "����"},
	{"325", "���"},
	{"3256", "���"},
	{"36", "����Ŷ�����ɵ��͹����ů������"},
	{"362", "˼������ͬ����Ա�����"},
	{"3622", "���������������������������������깰�ů��"},
	{"36222", "��Ŀ�Ҿ������ຶ�����"},
	{"362222", "���������������"},
	{"3622226", "������"},
	{"3622223", "���������"},
	{"36222232", "�����������������"},
	{"36222236", "�"},
	{"36222233", "����"},
	{"36222234", "��"},
	{"36222242", "��"},
	{"36222245", "��������"},
	{"3622225", "��"},
	{"362226", "�����߶����������ʱ�����������"},
	{"3622262", "���߶����"},
	{"3622264", "������"},
	{"3622265", "ʱ�����������"},
	{"362223", "�����۫Ұ����"},
	{"3622232", "����۫Ұ�������������"},
	{"36222326", "�۫Ұ���"},
	{"36222323", "����"},
	{"36222324", "����������"},
	{"3622236", "��ɹ�������"},
	{"3622233", "�"},
	{"3622234", "ζ����������"},
	{"3622235", "�"},
	{"362224", "��˯��߼����հ����������������˲"},
	{"3622246", "߼����հ"},
	{"3622243", "���������"},
	{"3622244", "�"},
	{"3622245", "��߻������գ��˲"},
	{"36222452", "����"},
	{"36222456", "��գ"},
	{"36222455", "��˲"},
	{"362225", "ѣͫ��Ϲ������"},
	{"3622256", "���"},
	{"3622254", "�����"},
	{"3622255", "Ϲ"},
	{"36226", "��Ŷ�����ѽΧ������"},
	{"362262", "����������ž��Ͼ"},
	{"362266", "ѽ"},
	{"362263", "Χ����"},
	{"362264", "ҷ�������������"},
	{"3622642", "����"},
	{"3622646", "�����"},
	{"3622643", "����"},
	{"362265", "������"},
	{"3622654", "��"},
	{"36223", "Ҷ��ײ�ð�������ҭ���þ������������"},
	{"362232", "����������������������"},
	{"3622322", "��"},
	{"3622326", "�"},
	{"3622323", "����������"},
	{"3622324", "�������"},
	{"3622325", "����ҭ"},
	{"362236", "��ð�첸�þ�����"},
	{"3622362", "��ð�첸�þ�����"},
	{"36223626", "��"},
	{"36223623", "������������"},
	{"36223624", "ӳ��"},
	{"3622363", "��������"},
	{"3622364", "��"},
	{"3622365", "֨"},
	{"362233", "���������˻����"},
	{"3622336", "߽��خ������ޱɳ�"},
	{"3622333", "����"},
	{"3622334", "�����"},
	{"3622335", "��������"},
	{"362234", "Ѽ��������"},
	{"3622346", "Ѽ"},
	{"3622345", "��������"},
	{"362235", "�Ż�����"},
	{"3622356", "����"},
	{"3622354", "��"},
	{"36224", "�ǻ���԰��������߿������"},
	{"362242", "�ǻ�����"},
	{"362242", "��"},
	{"3622423", "����"},
	{"362246", "԰����������߿�����������޶�Ъ������"},
	{"3622462", "԰"},
	{"36224622", "����"},
	{"3622466", "������"},
	{"3622463", "������"},
	{"3622464", "߿�����������޶�Ъ"},
	{"3622465", "������"},
	{"362243", "����������ସ���"},
	{"3622432", "��"},
	{"3622436", "��ସ���"},
	{"3622434", "��"},
	{"3622435", "����"},
	{"362244", "����"},
	{"362245", "Ż���ٷ�߾����ů����"},
	{"3622454", "����"},
	{"3622455", "��߾����ů����"},
	{"36225", "������Ӱ������������������������"},
	{"362252", "��"},
	{"3622525", "�Ű�"},
	{"362256", "������������"},
	{"362254", "���"},
	{"362255", "����"},
	{"3626", "�����ɱ��ں�п���������ɤ˱��̾��Х��Ӵ��ߵ߶߷ߺ����������������������������"},
	{"36262", "������������������Х"},
	{"362622", "������Х"},
	{"362626", "��"},
	{"362624", "��������"},
	{"36266", "���Ӵ�ߺ������"},
	{"362662", "��"},
	{"362666", "��"},
	{"362664", "��"},
	{"362665", "ߺ��"},
	{"36263", "��ߵ"},
	{"362632", "���ذ�"},
	{"362636", "��"},
	{"362633", "��"},
	{"36264", "��߶߷���α�"},
	{"362642", "����"},
	{"3626436", "��"},
	{"36265", "̾ɤ�����˱������"},
	{"362656", "ɤ�"},
	{"362653", "��"},
	{"362654", "��˱������"},
	{"3623", "�бĲ䳪�����ŷȸ�ƹ̺���Ȼ׼��׾���������·����������Ʒ��������Ƚ������̣̤��ͬ��θ��������ֺ֩������������������������������"},
	{"36232", "����Ƚ�������η���ȳ�"},
	{"362322", "�ȳ�"},
	{"3623226", "�η��"},
	{"3623223", "����"},
	{"3623224", "��"},
	{"362326", "�����ʻ�����"},
	{"3623266", "��"},
	{"3623263", "��"},
	{"3623264", "�л�����"},
	{"362323", "�����³�����������������Ű�����"},
	{"3623232", "�����³�ֺ�ֿ�̣�����߱�����"},
	{"36232322", "���ϵ�Ծ��������"},
	{"362323226", "����"},
	{"362323223", "�����������"},
	{"362323224", "���Ű�����"},
	{"36232326", "���վ�����ӻ������̤"},
	{"362323262", "���վ�"},
	{"362323266", "����̤"},
	{"362323264", "����"},
	{"362323265", "����ӻ��"},
	{"36232323", "ֺ�ֿ�̣�����߱�������"},
	{"362323232", "ֺ��"},
	{"362323236", "��̣�����߱�����"},
	{"362323233", "��"},
	{"36232324", "��Ծ�����������������赸��"},
	{"362323242", "��Ծ��������"},
	{"362323246", "�ڶ������"},
	{"3623232464", "����"},
	{"3623232465", "��·��"},
	{"362323243", "������"},
	{"362323244", "��"},
	{"362323245", "���������赸��"},
	{"36232325", "����������������������������ɴ�"},
	{"362323256", "����"},
	{"362323254", "�����"},
	{"362323255", "���ɴ�"},
	{"3623236", "θ�й���ǲ��"},
	{"3623234", "ſ"},
	{"3623235", "��"},
	{"362324", "�������"},
	{"362325", "���Ϻ������������������������"},
	{"3623252", "���������"},
	{"36232522", "������"},
	{"362325223", "��"},
	{"362325224", "�"},
	{"36232526", "�������"},
	{"36232523", "��Ϻ�����������������"},
	{"362325232", "�����������������"},
	{"3623252322", "��"},
	{"3623252323", "�"},
	{"362325236", "���������"},
	{"362325233", "���������������������"},
	{"3623252332", "������������"},
	{"36232523322", "����"},
	{"36232523326", "�������"},
	{"3623252336", "������"},
	{"3623252333", "��"},
	{"3623252334", "�"},
	{"3623252335", "�����"},
	{"362325235", "Ϻ"},
	{"362325242", "������"},
	{"36232525", "�����"},
	{"3623256", "��˼���������Ӽ��"},
	{"36232536", "����������Ы���׹�"},
	{"362325362", "��������Ӭ��"},
	{"362325363", "�׹�"},
	{"362325364", "��"},
	{"36232534", "��"},
	{"36232535", "���"},
	{"36232542", "�������֩������������������"},
	{"362325422", "�"},
	{"362325426", "��"},
	{"362325423", "������������"},
	{"36232546", "������"},
	{"36232543", "���������"},
	{"36232545", "�����ȸ�������"},
	{"3623255", "����������������"},
	{"36232556", "�������"},
	{"36232554", "���������ɲ������"},
	{"36232555", "�����"},
	{"36236", "��ͬ�̾�����������������Գ�௺ȿ޾�����"},
	{"362362", "��ͬ����������ܹ�"},
	{"3623622", "��"},
	{"36236222", "�����������"},
	{"36236226", "��"},
	{"36236223", "�����Գ��"},
	{"36236224", "�ȿ޾�����"},
	{"3623626", "��"},
	{"3623623", "����Ʒ�����ι������"},
	{"3623624", "����"},
	{"362363", "���ܴ�����"},
	{"362364", "Ա������ѫ�ǹ�����"},
	{"362365", "��"},
	{"36233", "����ۺ"},
	{"362332", "����ۺ"},
	{"362336", "����"},
	{"36234", "��"},
	{"36235", "߲�����������"},
	{"362356", "��"},
	{"362354", "���������"},
	{"3624", "�ȳԴ��߶��Ը����ߺ������������ȿȿ���Ŷ��ơǺ��ʷ������������������ҧ��ӽ��ֻ߳ߴ߸߹��������������������������������"},
	{"36242", "��߸զ��Ŷ��������"},
	{"36246", "��������߳ߴ�������ػ�����"},
	{"362462", "����"},
	{"362466", "����"},
	{"362463", "����"},
	{"362464", "�Ǵ�����"},
	{"362465", "������"},
	{"36243", "������������ơ���ƺ�����"},
	{"362432", "�����Ψ���ݻ�"},
	{"362436", "������������ơ���ƺ�"},
	{"362434", "��"},
	{"362435", "Ψ����"},
	{"36244", "������"},
	{"36245", "ֻ���ʷ������ɶ����������Ǻ�������Ƚ�����"},
	{"362452", "����"},
	{"3624522", "��ɶ"},
	{"3624523", "����"},
	{"3624524", "��"},
	{"3624525", "��"},
	{"362456", "����Ǻ��"},
	{"362453", "����"},
	{"362454", "��������"},
	{"362455", "�����Ƚ�"},
	{"3625", "�����������������������������������"},
	{"36252", "���ࡺߺ���ҧ�������������������"},
	{"362526", "���"},
	{"362523", "�ߺ���"},
	{"362524", "ҧ����������"},
	{"3625254", "���������"},
	{"36256", "�ӽ���������"},
	{"36254", "����߹���������"},
	{"36255", "����������������"},
	{"366", "�Ǻ�������������������������������������"},
	{"3666", "��"},
	{"3664", "��"},
	{"36642", "��"},
	{"3665", "�Ĺ����������������������º���������"},
	{"36656", "��������������������"},
	{"366563", "����������"},
	{"3665636", "�����������躡����������������������"},
	{"36656362", "����"},
	{"366563622", "��������������"},
	{"3665636225", "����������"},
	{"3630", "���������ķ�ñ������"},
	{"3632", "������Ƕ̿Ͽ������ո���������������"},
	{"36322", "�������"},
	{"36326", "����ո"},
	{"363232", "���Ƕ��������������"},
	{"363236", "������"},
	{"363233", "�Ƕ������"},
	{"363234", "��"},
	{"363242", "�������������̿���"},
	{"363243", "�����"},
	{"363245", "��̿���"},
	{"363254", "��Ͽ"},
	{"3636", "�ؾ�����Բ�������������������������"},
	{"36362", "�����ܿ���Բ�������"},
	{"363623", "Բ"},
	{"363624", "�����"},
	{"363625", "��"},
	{"36366", "�"},
	{"36363", "�����"},
	{"36364", "��"},
	{"36365", "Ỿ���"},
	{"3633", "�շ��ڻϿ�����ñ������������֡�����������������������������"},
	{"36332", "���������������������������֡��������"},
	{"363323", "�������"},
	{"363324", "������"},
	{"363325", "����"},
	{"36336", "���������ñ�̻��"},
	{"363364", "���"},
	{"36333", "�"},
	{"36334", "��"},
	{"36335", "��"},
	{"3634", "���޶뷫��������Ρ������������������������������"},
	{"36342", "����ὶ�����Ρ"},
	{"36346", "�귫᰷����������"},
	{"36343", "���ʹ��"},
	{"36345", "����������"},
	{"3635", "�紱�������������������"},
	{"36352", "�ƴ������"},
	{"36354", "����������"},
	{"36355", "����"},
	{"364", "�ļ��������ƹ�ͼ�򸳻߼���������������������"},
	{"3646", "����ͼ��߼�"},
	{"36462", "��"},
	{"36464", "��"},
	{"36465", "ͼ"},
	{"3645", "�����ڰܱ�ƴͶķ����չ��߼�¸����������������Ӥ������������׬����������������������"},
	{"36452", "������������������"},
	{"364526", "����"},
	{"364523", "������"},
	{"364524", "���"},
	{"36456", "����"},
	{"36453", "��������Ӥ�����"},
	{"364542", "�˰�"},
	{"364546", "��¸��"},
	{"364544", "��"},
	{"364545", "�������"},
	{"36455", "��������������׬"},
	{"365", "��īĬǭȦ��������������������"},
	{"3654", "����Ȧ������"},
	{"36542", "��������Ȧ������"},
	{"365422", "��"},
	{"3654223", "����"},
	{"3654224", "Ȧ"},
	{"365425", "��"},
	{"3655", "ǭ"},
	{"33", "ҵ�ɼ������������ͽ���"},
	{"336", "���;ɼ�����"},
	{"3362", "��"},
	{"3363", "���������"},
	{"3365", "����������"},
	{"33655", "��"},
	{"334", "�����������"},
	{"3342", "���ټ���"},
	{"335", "ҵ����������"},
	{"3354", "ҵ����������"},
	{"33542", "ҵ����������"},
	{"34", "�������ȸ��ʡʦ˧��"},
	{"342", "ʦ"},
	{"3423", "ʦ"},
	{"346", "��"},
	{"3462", "��"},
	{"343", "˧"},
	{"3436", "˧"},
	{"345", "�ټ���ʡȸ����"},
	{"3454", "����ʡȸ"},
	{"35", "�������ҫФ������"},
	{"4", "���������¼��͵��ð�ʳƬذǧ�绯���Ծ�Ѫ������ë����"},
	{"42", "�������������쳤����Ѭʧ����ۥ"},
	{"422", "����ݴ�������Ǯ��ʧ��"},
	{"4222", "�����۸ƾ���ϳա�������������������پ�����������������������������"},
	{"42226", "Ǯ�������������ê�����ǯ�����������"},
	{"422262", "���Ҷ���������ǯ���������"},
	{"4222623", "��ǯ�����������"},
	{"42226232", "����������"},
	{"42226236", "������������"},
	{"42226233", "ǯ����������������"},
	{"422262336", "����"},
	{"422262333", "��ê"},
	{"422262334", "��"},
	{"422262335", "�"},
	{"42226234", "��"},
	{"4222624", "�����������������"},
	{"42226243", "������"},
	{"42226245", "�������"},
	{"4222625", "������"},
	{"422266", "���ƾ�����������������������������"},
	{"4222662", "����﷾������"},
	{"42226626", "����"},
	{"42226623", "ť"},
	{"42226624", "�����"},
	{"4222666", "������"},
	{"42226662", "��"},
	{"42226666", "��"},
	{"4222663", "�����"},
	{"4222664", "�����"},
	{"4222665", "������"},
	{"422263", "��������������ͭ���ӹ�����������"},
	{"4222632", "��ֱ���ա��������"},
	{"4222636", "������ｳ����ﾸֱ���ա��ͭ������"},
	{"42226362", "����ｳ�����������"},
	{"422263622", "����"},
	{"422263623", "������������ͭ������"},
	{"4222636232", "��������"},
	{"4222636236", "��ͭ������"},
	{"4222636233", "��"},
	{"422263624", "��"},
	{"42226363", "������"},
	{"42226364", "�ֱ���ա"},
	{"4222633", "�"},
	{"4222635", "������������"},
	{"4222642", "������ǥ�������������"},
	{"42226426", "�"},
	{"42226423", "ǥ����������"},
	{"42226424", "��"},
	{"4222646", "����������Ǧ�平����"},
	{"42226466", "������"},
	{"42226463", "Ǧ��"},
	{"4222643", "�˲����������׶����"},
	{"4222644", "í����������"},
	{"4222645", "����������������"},
	{"422265", "�����������������þ���������������"},
	{"42226523", "���͸�����п���¾�����"},
	{"42226524", "����ҿ�¶�����������"},
	{"42226525", "п���¾�������"},
	{"4222656", "���"},
	{"4222653", "��������"},
	{"4222654", "����þ������������"},
	{"4222655", "�����趧��������"},
	{"42223", "��"},
	{"42224", "����"},
	{"4226", "�ְ����������������ƶͷ��շ���ֹ������ؼ��½�������������ëíþ��"},
	{"42262", "벸����������������ǥǮ������������̺������"},
	{"42266", "����릷����"},
	{"42263", "ձ믳���"},
	{"42264", "�"},
	{"422642", "ϳ�"},
	{"422646", "��"},
	{"422643", "��"},
	{"42265", "������̺���"},
	{"4223", "ţ���糸�׹���ȱж����ۥ�������"},
	{"42232", "����ĵж��������"},
	{"42236", "󾶪�Ƹ�ȱ������"},
	{"422365", "��"},
	{"42233", "����"},
	{"42234", "����ۥ����"},
	{"42235", "��"},
	{"4224", "��ʧ���ݵ��̽þ�ʸ֪������������"},
	{"42242", "��"},
	{"42244", "���"},
	{"42245", "ʧʸ֪�ǵ���������"},
	{"422452", "��鰶���"},
	{"4224523", "����"},
	{"422453", "֪��"},
	{"422454", "��������"},
	{"422455", "��"},
	{"426", "����ر�����췱ÿ��������ع����"},
	{"4262", "���Ҷ�"},
	{"4266", "ÿ����ع��"},
	{"4263", "��"},
	{"4264", "��"},
	{"4265", "����"},
	{"423", "ǧ��Ǩ���ȸ洹��������"},
	{"4232", "������������ѡ�������ɴ���ĵ����է��������"},
	{"42322", "է������������"},
	{"423223", "������"},
	{"42326", "͢��"},
	{"42323", "����۬������"},
	{"42324", "������ѡ����"},
	{"42325", "����"},
	{"4236", "��Ѭ��Ƭ��ư�"},
	{"42362", "�عθ��"},
	{"42364", "�ư�"},
	{"42365", "Ѭ"},
	{"4233", "�ǵйι�����ʣ�����������ι���ʣ�´ǵ�������"},
	{"42332", "��ʣ"},
	{"42336", "�������ҵ��ʴ������"},
	{"423362", "����"},
	{"4233626", "��"},
	{"4233624", "�������"},
	{"4233625", "�ʴ�"},
	{"4234", "��̵��弾����ί��̳�����ͻ�������ί������"},
	{"42342", "�"},
	{"42346", "��"},
	{"42345", "����������������������"},
	{"423452", "�����������������"},
	{"423456", "˽ί����͸κ��"},
	{"423453", "������������������"},
	{"4234536", "��������������"},
	{"42345362", "�������������"},
	{"423453623", "�������"},
	{"423453624", "������"},
	{"42345364", "��"},
	{"4234534", "��"},
	{"4234535", "��"},
	{"4234542", "��"},
	{"4234546", "ͺ�������ǳ�������"},
	{"4234543", "������"},
	{"4234545", "��ϡ�������"},
	{"423455", "��������˰���"},
	{"42356", "Ǩ"},
	{"42355", "�ڳ�"},
	{"424", "��ز"},
	{"4243", "��"},
	{"4245", "ز��������"},
	{"42452", "��"},
	{"42453", "�"},
	{"42454", "����"},
	{"425", "�ȱʵڼ��㱿���߳���������������ʱ�"},
	{"4254", "�ͼ����������Ц��������ѹܼ�����¨ǩͲ��������������������������������"},
	{"42542", "�ÿ�Ｎ�ļ������湿������������"},
	{"425425", "�õ������������������������"},
	{"4254252", "��Ｎ"},
	{"42542522", "�ļ���"},
	{"425425223", "��������"},
	{"425425224", "��"},
	{"425425225", "��"},
	{"42542526", "��������������"},
	{"42542523", "������������������"},
	{"425425236", "�������������"},
	{"425425233", "�������"},
	{"425425234", "������"},
	{"42542524", "������"},
	{"4254256", "�������������׭������"},
	{"42542566", "����׭"},
	{"42542563", "��"},
	{"42542564", "����"},
	{"42542565", "����"},
	{"4254253", "���������ɸ��Ͳ����"},
	{"42542536", "��Ͳ����"},
	{"425425363", "����"},
	{"425425364", "����"},
	{"42542534", "ɸ"},
	{"42542535", "��"},
	{"42542542", "Ц���������ܴ�ǩ�ɷ�������������"},
	{"42542546", "�������ݽ�����"},
	{"42542543", "��������������"},
	{"42542544", "��"},
	{"42542545", "�ܴ�ǩ"},
	{"4254255", "�Ҽ�ƪ��ݴ�����¨������ܲ�������"},
	{"42542556", "ƪ"},
	{"42542553", "��"},
	{"42542554", "��¨����"},
	{"42542555", "��ܲ�������"},
	{"46", "������������������ó����ذ�踺��"},
	{"462", "����ӡ���ܷ�������"},
	{"4622", "��ʤ��̥��������ӷ��֬������������������������������������"},
	{"46222", "������·��������Ĥ��"},
	{"462226", "��������"},
	{"462223", "�Ǹؽ�����֫�������������Ĥ��"},
	{"4622236", "֫����������"},
	{"4622233", "����Ĥ��"},
	{"4622234", "ϥ"},
	{"4622235", "��"},
	{"462224", "���������ʿ�����"},
	{"462225", "Ϣ"},
	{"46226", "˦�������ȳ�����в̥��"},
	{"462262", "��������"},
	{"462266", "��"},
	{"462263", "��"},
	{"462264", "��в"},
	{"462265", "̥��"},
	{"46223", "������������������"},
	{"462232", "��������"},
	{"4622326", "��"},
	{"462236", "뾵�������������������������"},
	{"4622362", "����������"},
	{"46223623", "����������������"},
	{"46223624", "��"},
	{"46223645", "��"},
	{"462235", "����"},
	{"46224", "ʤ����𩸹���մ���"},
	{"462246", "����������֬���ɿ�"},
	{"4622462", "���մ���"},
	{"4622466", "���ɿ�"},
	{"4622463", "��֬"},
	{"4622464", "����"},
	{"4622465", "��"},
	{"462243", "������Ƣ"},
	{"4622432", "��"},
	{"4622436", "����Ƣ"},
	{"462244", "��"},
	{"462245", "��������������"},
	{"46225", "�ܷ�ӷ���ܰ�������Ѱ���������ǻ������ŧ"},
	{"462252", "�����ེ�갹�Ը�Ҹ�"},
	{"4622524", "�ེ�갹�Ը�Ҹ�"},
	{"4622525", "�ܰ���"},
	{"462256", "��ŧ"},
	{"4622564", "ŧ"},
	{"462254", "����������������"},
	{"4622542", "���"},
	{"4622543", "��"},
	{"462255", "����������ǻ����"},
	{"4626", "����ۡ������ӡۡ"},
	{"46266", "��"},
	{"46263", "ӡ��"},
	{"46265", "صۡ�"},
	{"462656", "ۡ"},
	{"462654", "�"},
	{"4623", "���������������"},
	{"4624", "Σղ��ղ"},
	{"466", "��ɫϵӭ��ۻ����ӭϵط"},
	{"4662", "��������������������ɷ�������ۻ���������������"},
	{"46622", "ۻ�������޽����Ķ�������"},
	{"466226", "���޽���"},
	{"466224", "ɷ��"},
	{"466225", "��"},
	{"46626", "��"},
	{"466263", "�����"},
	{"466264", "��"},
	{"46623", "�ζ�����������"},
	{"466233", "��������"},
	{"466234", "��"},
	{"466235", "��"},
	{"4666", "��������"},
	{"46664", "�"},
	{"46665", "��"},
	{"4663", "ɫ����ʴӭ��"},
	{"4664", "��������������������������ڱ����������"},
	{"46642", "�������ζ�"},
	{"46646", "������������"},
	{"466466", "��"},
	{"466463", "��"},
	{"466464", "����"},
	{"466465", "��"},
	{"46643", "����"},
	{"46644", "��"},
	{"46645", "������������"},
	{"4665", "ϵ����ӯ���ȹݽ�ط������"},
	{"46652", "��"},
	{"46656", "ϵ"},
	{"46653", "ط"},
	{"46654", "����"},
	{"46655", "��"},
	{"463", "��³������������ּۼ"},
	{"4632", "��"},
	{"46323", "��"},
	{"4636", "³������鸺������꾨����������ּۨ۾����������������"},
	{"46362", "���������������³������������������������"},
	{"463622", "Ѯּ��ۨ��������������"},
	{"4636264", "۾"},
	{"4636232", "����������������������³����������������"},
	{"46362322", "����������������������"},
	{"463623222", "����������������"},
	{"4636232223", "������������"},
	{"46362322236", "������"},
	{"46362322233", "������"},
	{"4636232224", "����������"},
	{"4636232225", "����"},
	{"463623226", "��������"},
	{"463623223", "����������������������������"},
	{"4636232236", "³����������������������"},
	{"46362322362", "��������"},
	{"46362322363", "��"},
	{"4636232233", "��"},
	{"4636232242", "������"},
	{"4636232246", "������"},
	{"4636232243", "������"},
	{"4636232245", "����"},
	{"463623225", "�о�����������������"},
	{"4636232252", "����"},
	{"4636232256", "��"},
	{"4636232254", "��������"},
	{"46362326", "����"},
	{"46362324", "��"},
	{"4636246", "����"},
	{"46362465", "��𶹻"},
	{"4636245", "ۼ"},
	{"463632", "����"},
	{"463645", "��"},
	{"4633", "��"},
	{"464", "���ҷ�îɾ�������������з��"},
	{"4642", "��������������̡����ӱ��Գ������"},
	{"464223", "������"},
	{"464224", "������"},
	{"46426", "��"},
	{"46423", "è����Գ����̡�"},
	{"46424", "�����"},
	{"46425", "��"},
	{"4646", "�����ݺ�îɾ�����������������𯷸ɾ�����ǽ�î�������������ݺ�з�����"},
	{"46462", "���������������������з"},
	{"464622", "���������ɾ"},
	{"4646223", "��������������������з"},
	{"464626", "���"},
	{"464623", "��ɾ"},
	{"46466", "��������"},
	{"464662", "������"},
	{"46463", "î�"},
	{"46464", "��"},
	{"46465", "����"},
	{"4643", "�����������˾���ʨ��"},
	{"464362", "�������⣶��ɱ����"},
	{"4643623", "⫶����"},
	{"464366", "��"},
	{"464363", "�"},
	{"464364", "��"},
	{"46434", "ʨ"},
	{"4644", "��Һ���������������"},
	{"46442", "���"},
	{"46446", "�������"},
	{"46443", "��غ�"},
	{"46444", "��"},
	{"46445", "�����������"},
	{"4645", "��ǷǷ�ҽ�����������"},
	{"46452", "���������"},
	{"46456", "��"},
	{"464562", "����"},
	{"46453", "�"},
	{"46454", "������"},
	{"46455", "�����"},
	{"465", "������ô��Ȼ�����񱸷�"},
	{"4652", "������ͮ���������"},
	{"46522", "���"},
	{"46526", "�������"},
	{"465263", "������"},
	{"4652635", "����"},
	{"46523", "��"},
	{"46524", "ͮ"},
	{"4656", "��óԹ������ԧ����"},
	{"46562", "��������"},
	{"465622", "��"},
	{"465623", "��"},
	{"465625", "��"},
	{"46566", "��Թԧ"},
	{"46563", "��"},
	{"46564", "��"},
	{"465646", "����ó��"},
	{"465643", "��ó��"},
	{"46565", "��"},
	{"4653", "�������������������"},
	{"4654", "�������⸷�ظ���"},
	{"4655", "����Ȼ����"},
	{"43", "�α��������¸�׷����ض�Ѻ��θ�"},
	{"432", "�����ʹ��ծֵ��������������ٱٺ��ٻ��ٺ�����"},
	{"4322", "����ΰ�������ٺ����"},
	{"43222", "����ٱ��ٺ����"},
	{"43226", "ΰ��"},
	{"43223", "ٻծ�����"},
	{"4326", "�浹���ٴ�����ľ�Ƭ�����������"},
	{"43262", "������������������������"},
	{"432626", "����������������"},
	{"4326265", "��������������"},
	{"43262655", "��"},
	{"432626556", "������������"},
	{"432623", "�"},
	{"432624", "��������"},
	{"43266", "����"},
	{"43263", "��"},
	{"43264", "����������"},
	{"43265", "����ֶٴ���ᷴ������"},
	{"432652", "ֶٴ��"},
	{"432656", "�"},
	{"432653", "ᷴ���"},
	{"432654", "��"},
	{"432655", "��"},
	{"4323", "������ʲ���������ʹ�����������ѽ�����������ֵ٥٦ټ���������ƹٲ��������"},
	{"43232", "�����̼�����٥������ƹ���б�"},
	{"432322", "�̼�"},
	{"432326", "����"},
	{"432323", "٥������"},
	{"432324", "ƹ"},
	{"4323246", "��"},
	{"4323245", "��"},
	{"432325", "��"},
	{"432362", "��㸵�Ⱥν�ʹ"},
	{"4323622", "�㸵��"},
	{"4323626", "��"},
	{"4323623", "��"},
	{"4323624", "ʹ"},
	{"432363", "����"},
	{"4323645", "��"},
	{"432365", "��"},
	{"4323653", "ٳ"},
	{"432332", "٦����ټ"},
	{"432336", "����ֵ"},
	{"432334", "��"},
	{"432335", "����ٲ�"},
	{"4324", "���۷�������������٨"},
	{"43242", "��"},
	{"43246", "����"},
	{"43243", "�Ӱ�٧"},
	{"43245", "��٨����а���"},
	{"4325", "����"},
	{"436", "�������������ּ�����"},
	{"4362", "���׷�������������׷���׻�����������������������"},
	{"43622", "���Իʳ����ض���ǰ�"},
	{"436222", "�Ծ˻��������������"},
	{"4362226", "������"},
	{"43622265", "��"},
	{"43622236", "�Ǿ�"},
	{"436222362", "��"},
	{"4362224", "���乪�ٸ������ɰ�"},
	{"436226", "Ȫ"},
	{"436223", "��������������"},
	{"4362236", "����������"},
	{"436224", "����ۯ�������"},
	{"4362242", "����ۯ����"},
	{"4362246", "��������������"},
	{"43622465", "��"},
	{"4362243", "��"},
	{"4362245", "�"},
	{"436225", "��������"},
	{"43626", "����׷"},
	{"43623", "������"},
	{"43624", "��٣٩�ƾ�Ƨ"},
	{"43624665", "��������������"},
	{"4366", "����"},
	{"4363", "��������Ѫ��غ��غ"},
	{"436332", "Ѫ����"},
	{"4364", "��ض����٤��"},
	{"43646", "��"},
	{"43643", "٤"},
	{"43645", "��ضα"},
	{"4365", "����������ٰٸٹ��"},
	{"433", "��ئ˳�ɺ�߳�����������"},
	{"4332", "��˳����ٽپ"},
	{"4336", "�����߶���������ұ����ߴٺ��żٶ��"},
	{"43362", "��ٶٵ�����ٵ�ٷ�¶�������"},
	{"433622", "�챣��ż����"},
	{"4336224", "��"},
	{"433623", "�ٵ�ٷ�¶�������"},
	{"433624", "��"},
	{"43363", "���ش߲��ش�"},
	{"433633", "��"},
	{"433634", "��"},
	{"433645", "��"},
	{"4334", "������"},
	{"43342", "����"},
	{"433465", "ٿ��"},
	{"43354", "���ȳ���"},
	{"4342", "����٪��Ǫ����ƾ��������"},
	{"43426", "������������"},
	{"43423", "Ǫ����ƾ��������"},
	{"43424", "��"},
	{"4346", "�����Ӷ���������ٻ���Ӷ�޵ͻ�������ٿ��������١��"},
	{"43462", "Ӷ�ͻ������ٻ�����"},
	{"434626", "��"},
	{"434623", "������"},
	{"434624", "��"},
	{"434663", "������"},
	{"434664", "����"},
	{"43463", "����������١����"},
	{"43464", "��"},
	{"43465", "��١����"},
	{"4343", "���������ղ����¿�ɵ��"},
	{"43436", "���¿�ɵ��"},
	{"434362", "��"},
	{"43435", "��"},
	{"4345", "���ۼ��������٬������٫��͵���۷ݿ���٬"},
	{"43452", "٬��͵"},
	{"43456", "����"},
	{"43453", "٫"},
	{"43454", "�׼���"},
	{"43455", "���"},
	{"435", "������Ｏ��ͣλ����"},
	{"4352", "������٭����������λ��ס�������Ű���ͣ����٭������������ٮ��"},
	{"435222", "�������ۼ���������"},
	{"435223", "ס��"},
	{"43523", "ͣ��"},
	{"43524", "����ٮ٭��"},
	{"43525", "λ������"},
	{"4356", "��ƫ��ƫٯ��"},
	{"4353", "��"},
	{"4354", "���α�����;�ɮ"},
	{"4355", "��٢������������٢��"},
	{"44", "���д���������㴬��"},
	{"442", "�������������ش���ܶ�"},
	{"4426", "ش"},
	{"4423", "�������������˶�����"},
	{"446", "�۷����Ϻ���������"},
	{"4462", "����"},
	{"4465", "�󲰲ն�����ͧ��������������������������������ն�"},
	{"44652", "������������������������������ͧ��"},
	{"446525", "����������������������������"},
	{"4465256", "����"},
	{"4465253", "��������������"},
	{"4465254", "����������������ͧ��"},
	{"4465255", "������������"},
	{"44655", "�Ϸ��"},
	{"446556", "��"},
	{"446554", "�"},
	{"443", "���������͵»�����"},
	{"4432", "��ͽ�����������ó��ʹ���ͽ��"},
	{"44322", "��"},
	{"44326", "��"},
	{"44323", "����ͽ�ͽ��õ�"},
	{"44325", "��"},
	{"4436", "�˾��ᾶ�ɱ˺����ײ����з������ƶ"},
	{"4433", "����΢���������黲��������û�΢����"},
	{"44332", "����"},
	{"44336", "�޻���΢�����"},
	{"44335", "��"},
	{"4434", "����ѭ����������ѭ�����������������"},
	{"44342", "����"},
	{"44346", "�������"},
	{"44343", "��"},
	{"44344", "ѭ"},
	{"44345", "����"},
	{"44352", "����"},
	{"44356", "��"},
	{"44354", "��"},
	{"44355", "����"},
	{"45", "�˽�˹����ְ����ȫ���κ���"},
	{"452", "�ϻ�����ȫ��ϣб������;б����ۦ����"},
	{"4522", "��"},
	{"45226", "���ܻ���;ۦ��б�"},
	{"45223", "ȫ�������"},
	{"4526", "ɱɲ����ػ��߱��ػ߱"},
	{"45264", "ɱ��ɲ��ػ"},
	{"452645", "����ػ"},
	{"4523", "���������������Ϻ�����������������"},
	{"45232", "��"},
	{"45236", "������쨺����ø��ø�"},
	{"452362", "������������"},
	{"4523626", "���"},
	{"4523623", "����"},
	{"4523624", "�ø�"},
	{"452366", "��"},
	{"452345", "ۧ߱"},
	{"4524", "�ۭۧ�����ϣۭۧ�"},
	{"45243", "��ϣۭ�"},
	{"4525", "���ݽ�"},
	{"45255", "�ݽ���"},
	{"456", "�ִ�������ƶ��������꨽���"},
	{"4566", "��"},
	{"45662", "�"},
	{"45663", "��"},
	{"45664", "����"},
	{"4563", "�ײ����з������ƶ��"},
	{"45642", "�а�"},
	{"45643", "��ƶ��"},
	{"45645", "��"},
	{"4565", "�ͷ�������"},
	{"45652", "����"},
	{"45656", "��"},
	{"453", "������"},
	{"453232", "��"},
	{"4536", "��"},
	{"454", "�ִӴԵ�����ү����"},
	{"4542", "������Ϥ��۶��"},
	{"45426", "��"},
	{"45423", "Ϥ������۶��"},
	{"4542345", "Ϥ�����ͷ�۶"},
	{"454234536232", "����۶"},
	{"4546", "�ؽ�"},
	{"4545", "ү���������ָ�������س�����ӴԸ�������������"},
	{"45452", "����ү���ʸ�"},
	{"454522", "��"},
	{"454523", "��ү����"},
	{"454536", "��������"},
	{"45454", "�ڸ���"},
	{"455", "�ɲʽ���ò����ʳ��ң"},
	{"4552", "��"},
	{"45524", "����"},
	{"4556", "�����ʳ�������ݺ�����̰��������̰����"},
	{"45562", "ʳ"},
	{"45563", "��̰�"},
	{"45565", "�������������"},
	{"455652", "�����"},
	{"455656", "������"},
	{"4554", "�������ɡ��������Ҩ��������ò�������ɡ˴ۮ�ʲ�������"},
	{"45542", "�ɡ������"},
	{"4554662", "����ۮ"},
	{"4554665", "��"},
	{"4554642", "�ײ��������ѱ���ò����"},
	{"4554644", "��������������ò������"},
	{"45546442", "������"},
	{"45546446", "��"},
	{"45546444", "�ѱ���ò����"},
	{"4554363", "��"},
	{"4554364", "��"},
	{"455442", "ң����"},
	{"455443", "Ҩ"},
	{"455456", "�ܰ���˴"},
	{"5", "��Ϊ��ǰ��û˵����л����ͷ��֮������������Ӯ����"},
	{"52", "��������������Ӧվ������"},
	{"522", "�ն�������������"},
	{"5226", "��������������"},
	{"5223", "ڡ����ڡ����"},
	{"526", "�������������Ӯ����"},
	{"5262", "��"},
	{"5266", "å������Ӻ�����ӷ�Ӻå�ʱ�"},
	{"5263", "��ä��������Ӯ"},
	{"5264", "������������������ʩ�������"},
	{"5265", "��������ұ��ұ��"},
	{"523", "��ߺ����Ϳ�����װ��"},
	{"5232", "׳״װ"},
	{"5236", "�������������ø߸�Ķ��ױ�����պ���Ϳ���ͤ�����а����ع���������ȿ����˥��"},
	{"52362", "��˥"},
	{"523626", "������������������"},
	{"5236266", "���������������"},
	{"52362662", "������"},
	{"523626626", "��"},
	{"5236266264", "��"},
	{"52362662645", "��"},
	{"523626624", "��"},
	{"5236266242", "��"},
	{"5236266246", "��"},
	{"52362665", "��"},
	{"5236264", "������"},
	{"523623", "��Ķ����ȿ����"},
	{"5236232", "Ķ"},
	{"5236236", "����ȿ����"},
	{"52362362", "��ȿ������"},
	{"523623622", "ȿ"},
	{"52362363", "����"},
	{"523623636", "��"},
	{"5236234", "��"},
	{"523624", "����"},
	{"5236246", "��"},
	{"52362464", "��"},
	{"523625", "ͤ��������"},
	{"5236256", "��"},
	{"52362564", "��"},
	{"523625642", "��"},
	{"523625646", "��"},
	{"52363", "������"},
	{"523636", "��"},
	{"5236362", "��"},
	{"5233", "�������������������������������ͱ���������"},
	{"52334", "������殱��������������"},
	{"523345", "����殱��������������"},
	{"5233456", "��殱�"},
	{"52334564", "�"},
	{"52334565", "��"},
	{"5233453", "������"},
	{"52334536", "��"},
	{"523345364", "��"},
	{"5233454", "�����"},
	{"52334546", "�"},
	{"52334545", "��"},
	{"52334556", "��"},
	{"5234", "����������"},
	{"5235", "��"},
	{"524", "����༣������������Ч��"},
	{"5242", "���ȿ���ĥĦħ��������ĥׯ���ѱ�������ϯ��ħ����������������"},
	{"52422", "����ĥ����Ħ����ħ����ϯ������"},
	{"524224", "��"},
	{"52426", "���"},
	{"524264", "��"},
	{"52423", "ׯ��"},
	{"524236", "��"},
	{"524233", "�ն���ϯ������"},
	{"52423323", "��"},
	{"524233236", "ϯ"},
	{"52423325", "��"},
	{"52423325", "1��"},
	{"524233255", "��"},
	{"5242332555", "��"},
	{"5242345", "����ĥ����Ħ����ħ"},
	{"52423452", "��ĥ����Ħ����"},
	{"524234523", "ĥ"},
	{"5242345234", "����Ħ����ħ��"},
	{"52423452345", "��"},
	{"524234523454", "Ħ��"},
	{"5242345234546", "��"},
	{"5242345234543", "ħ"},
	{"5242345234554", "��"},
	{"5242446", "��"},
	{"524245", "����"},
	{"5242453", "��"},
	{"5246", "�����ɷŷ���������������������������������龻¹ʩ��������ӹ���������"},
	{"52462", "��ӹ�Ƹ��ٵ�����ͥͥ"},
	{"524622", "ӹ"},
	{"5246223", "��"},
	{"5246224", "��"},
	{"52462245", "��"},
	{"524623", "��"},
	{"524624", "��"},
	{"524662", "��ͥ"},
	{"524664", "ͥ"},
	{"52463", "��¹����������������"},
	{"524633", "¹����������������"},
	{"5246332", "��������"},
	{"52463322", "������"},
	{"524633226", "������������"},
	{"5246332264", "��"},
	{"52463322646", "��"},
	{"524633226465", "��"},
	{"5246332264654", "��"},
	{"52463322646542", "��"},
	{"52464", "�������������"},
	{"524642", "�������"},
	{"5246422", "��"},
	{"5246426", "���"},
	{"52464263", "��"},
	{"52464242", "�"},
	{"524642422", "�"},
	{"52464246", "���"},
	{"524642465", "�"},
	{"5246425", "�"},
	{"524646", "��"},
	{"524645", "��������������ɵ����ἣ�����"},
	{"5246452", "���������ɵ����ἣ�����"},
	{"52464524", "��"},
	{"524645245", "��"},
	{"5246456", "��"},
	{"5246453", "�ɵ�����"},
	{"52464536", "��"},
	{"524645364", "��"},
	{"5246453645", "��"},
	{"5246455", "�������"},
	{"52464556", "��"},
	{"52464554", "��"},
	{"52464555", "�"},
	{"52465", "����"},
	{"524656", "��"},
	{"5243", "������ҹ׼����"},
	{"52432", "��������ҹ׼����"},
	{"524324", "��"},
	{"52436", "������"},
	{"524362", "��"},
	{"5243623", "��"},
	{"52433", "��"},
	{"52434", "ҹ"},
	{"52435", "׼"},
	{"5244", "�׸�����ͥӥ������������������"},
	{"52446", "�ϵ��Ҹ����׸���������ӥ"},
	{"524462", "�Ҹ����׸���������ӥ"},
	{"524466", "��"},
	{"524464", "��"},
	{"52443", "��"},
	{"524432", "��"},
	{"5244326", "��"},
	{"5244323", "��"},
	{"524436", "��"},
	{"524434", "��"},
	{"5244343", "ӥ"},
	{"52445", "��"},
	{"5245", "���󲡼���������֢�ĳմ񶻾�������űƦȬ̱��Ӧ֢�����������������������������������̱񴯴ø�"},
	{"52452", "������ű����֢������"},
	{"524522", "����ű����֢������"},
	{"5245222", "�"},
	{"5245226", "��ű��"},
	{"52452262", "ű"},
	{"524522626", "��"},
	{"5245223", "��֢�����ⲡ����񮶻�����������"},
	{"52452232", "֢�����ⲡ����񮶻�����������"},
	{"524522323", "��"},
	{"524522325", "��"},
	{"52452236", "�����������񦶻"},
	{"524522362", "�������"},
	{"5245223623", "��"},
	{"52452236234", "�"},
	{"5245223625", "��"},
	{"5245223633", "�"},
	{"524522364", "��"},
	{"52452233", "������������"},
	{"524522332", "�"},
	{"524522336", "�"},
	{"524522333", "�"},
	{"524522334", "��"},
	{"524522335", "����"},
	{"5245223354", "��"},
	{"5245224", "��������Ʀ��"},
	{"52452246", "������"},
	{"524522464", "��"},
	{"524522465", "��"},
	{"52452243", "Ʀ"},
	{"52452254", "��"},
	{"524526", "�����������ܰ�����ȳƣ��ʹ̱��"},
	{"5245262", "���������ܰ�����ȳƣ��ʹ̱��"},
	{"52452624", "�"},
	{"524526243", "�"},
	{"5245266", "����"},
	{"52452664", "��"},
	{"5245263", "�ܰ�����ȳƣ��ʹ̱��"},
	{"52452632", "��"},
	{"52452634", "�"},
	{"524526346", "�"},
	{"5245264362", "��"},
	{"52452643623", "ȳ"},
	{"5245264365", "ƣ"},
	{"5245265", "�"},
	{"52452652", "��"},
	{"52452653", "ʹ"},
	{"52452654", "̱"},
	{"52452655", "��"},
	{"524523", "��þ����������񧰩�������"},
	{"5245232", "�þ����������񧰩�������"},
	{"5245236", "���������񧰩�������"},
	{"52452362", "���񧰩��"},
	{"524523622", "�"},
	{"5245236223", "��"},
	{"524523626", "��"},
	{"524523623", "��񧰩��"},
	{"5245236232", "�"},
	{"5245236236", "��"},
	{"5245236233", "��"},
	{"52452363", "��"},
	{"524523636", "��"},
	{"52452364", "�"},
	{"524524", "���ո�������Ӹ����Ѣ��������"},
	{"5245242", "�ո�������Ӹ����Ѣ��������"},
	{"52452426", "��"},
	{"52452423", "������"},
	{"524524234", "��"},
	{"5245242345", "��"},
	{"5245246", "Ӹ����Ѣ��������"},
	{"52452466", "���߻�Ѣ��"},
	{"524524665", "��"},
	{"52452463", "Ѣ"},
	{"524524636", "��"},
	{"52452464", "��"},
	{"52452465", "��"},
	{"524524655", "���"},
	{"5245246555", "��"},
	{"5245243", "������ի�������"},
	{"52452436", "����ի�������"},
	{"524524362", "��"},
	{"5245243633", "ի"},
	{"5245244", "�"},
	{"5245245", "Ȭ"},
	{"52452456", "��"},
	{"52452454", "��"},
	{"524524544", "��"},
	{"524524545", "��"},
	{"52452455", "�"},
	{"524525", "���������������������̵��"},
	{"5245252", "�������������������̵��"},
	{"52452524", "��"},
	{"524525245", "��"},
	{"52452525", "��"},
	{"524525254", "�"},
	{"52452536", "��"},
	{"5245254", "��"},
	{"52452542", "��"},
	{"524525423", "��"},
	{"52452543", "��"},
	{"52452544", "̵"},
	{"5245255", "��"},
	{"52456", "��®��������"},
	{"524562", "®"},
	{"524566", "��"},
	{"524563", "��"},
	{"524565", "��"},
	{"5245654", "��"},
	{"52453", "�����"},
	{"524536", "��"},
	{"5245362", "��"},
	{"52454", "���������Ӧ��Ч�����"},
	{"524542", "���������Ӧ��Ч���"},
	{"524543", "��"},
	{"5245433", "��"},
	{"524545", "��"},
	{"5245452", "��"},
	{"5245456", "��"},
	{"5245454", "Ч"},
	{"5245565", "��"},
	{"5245536", "�"},
	{"524554", "Ӧ"},
	{"525", "����������ͯ�����������ݱ粿�۶��������þ�������ͯ����վ���߾������ʰ�"},
	{"5252", "��������"},
	{"52523", "��"},
	{"525246", "��"},
	{"525243", "��"},
	{"5254", "������������������"},
	{"52542", "��������������"},
	{"525422", "��񴿢վ"},
	{"5254226", "��"},
	{"5254223", "���"},
	{"52542236", "�"},
	{"5254224", "�������"},
	{"52542246", "��"},
	{"52542244", "��"},
	{"52542245", "���"},
	{"525422454", "��"},
	{"525426", "�񴿢վ"},
	{"52542652", "�"},
	{"52542654", "��"},
	{"525423", "վ����ͯ��۵�Ӿ�������ؽ��ϲ��ʾ�짶�"},
	{"5254232", "վ"},
	{"5254236", "��ͯ۵�Ӿ�������ؽ��ϲ��ʾ�짶�"},
	{"52542362", "��ͯ۵�Ӿ�������ؽ�����"},
	{"525423622", "ͯ���"},
	{"5254236222", "۵"},
	{"52542362223", "������"},
	{"525423622234", "��"},
	{"5254236222344", "��"},
	{"5254236226", "���"},
	{"52542362264", "��"},
	{"5254236224", "������"},
	{"52542362246", "��"},
	{"525423622465", "��"},
	{"5254236225", "��"},
	{"525423626", "��"},
	{"525423623", "��"},
	{"525423624", "���"},
	{"5254236246", "�"},
	{"52542363", "��"},
	{"525424", "����������̸�����"},
	{"5254246", "��������̸�����"},
	{"52542464", "�"},
	{"5254244", "��"},
	{"52542444", "��"},
	{"52543", "��"},
	{"52545", "��"},
	{"525456", "��"},
	{"5254563", "�"},
	{"52545654", "��"},
	{"56", "�����Ʊظüǽ�������˵��֮ڢڥ"},
	{"5622", "�ڻ��������ڦڲڳ����ڲ�佲��ڦ�ڽ�����ڳ����г��ڪ۩"},
	{"56222", "ڲڳ"},
	{"562223", "ڳ"},
	{"56226", "��������"},
	{"562264", "��"},
	{"562265", "����"},
	{"5622654", "��"},
	{"56223", "ڦ����"},
	{"562232", "��"},
	{"5622323", "��"},
	{"56224", "�ڽ���"},
	{"562243", "��"},
	{"5622436", "��"},
	{"5626", "����д��г۩����ڪ��"},
	{"56262", "дڪ��۩��"},
	{"562626", "ڪ"},
	{"562623", "��۩��"},
	{"5626236", "۩"},
	{"56262364", "��"},
	{"562664", "��"},
	{"56264", "��"},
	{"562646", "г"},
	{"56265", "��"},
	{"5623", "��ڧʫڴ֤��ڵ��ڭ��̷��"},
	{"56232", "ڧʫڴ֤��ڵ��ڭ��̷��"},
	{"562322", "ʫ"},
	{"5623223", "ڴ"},
	{"562323", "֤��ڵ"},
	{"5623232", "��"},
	{"5623236", "ڵ"},
	{"562324", "��"},
	{"56236", "ڭ��̷�ɶ�"},
	{"562362", "��"},
	{"562363", "̷"},
	{"562365", "��"},
	{"5623655", "��"},
	{"56233", "��ı�ȵ���ŵڬ���ӻ���"},
	{"562332", "ı�ȵ���ŵڬ���ӻ���"},
	{"5623322", "��"},
	{"5623326", "��"},
	{"5623323", "��"},
	{"5623324", "ŵ"},
	{"562336", "ڬ"},
	{"5623365", "��"},
	{"562333", "��"},
	{"562335", "��"},
	{"56234", "��"},
	{"5624", "�����������ȱ��ع������������������"},
	{"56242", "��"},
	{"56246", "��ڣ����"},
	{"562464", "ڣ"},
	{"5624644", "��"},
	{"562465", "��"},
	{"56243", "������������������"},
	{"562436", "������������"},
	{"5624362", "��������"},
	{"56243626", "��"},
	{"56243623", "�����"},
	{"562436233", "��"},
	{"5624362335", "��"},
	{"5624363", "��"},
	{"562442", "���ع�"},
	{"5624425", "��"},
	{"562443", "��"},
	{"56245", "��کڶ��"},
	{"562456", "ک"},
	{"562454", "ڶ"},
	{"562455", "��"},
	{"5625", "��"},
	{"56254", "��"},
	{"566", "�����ʾ�����Ѷ��گ��Ѷڰ��گ��ڱڼ��"},
	{"5662", "��Ѷ�ʾ�"},
	{"56623", "Ѷ"},
	{"566236", "��"},
	{"56624", "��"},
	{"5663", "ڰ"},
	{"5664", "گ����"},
	{"56645", "��"},
	{"566453", "��"},
	{"5665", "��ڼ��ڱ����"},
	{"56652", "ڼ"},
	{"566526��"},
	{"56656", "��"},
	{"56653", "ڱ"},
	{"566536", "��"},
	{"56654", "��"},
	{"563", "����������ʶ��ԣ�����ν��������ڨ��áǴʶ��ڤګ��"},
	{"5632", "�÷���"},
	{"56322", "��"},
	{"563222", "��"},
	{"56326", "��"},
	{"5636", "���ʷ�����á��Ǵν����ڤڨګ������ν��������ڨ��áǴʶ��ڤګ��"},
	{"56362", "�����ʶ��á��ڤνǴ����"},
	{"563622", "����ʶ��á��ڤ"},
	{"5636222", "��"},
	{"56362224", "��"},
	{"5636223", "á"},
	{"5636224", "��"},
	{"5636225", "ڤ"},
	{"563623", "νǴ����"},
	{"5636232", "Ǵ��"},
	{"5636236", "��"},
	{"563624", "ʶ"},
	{"56363", "ڨ"},
	{"56364", "ګ"},
	{"5634", "���������ȹ��������ȹ̻��ԣ���������������������������޺��������������"},
	{"56345", "�������İ�����ȹԣ�������������ҹӽ�����̻��������������������������Ը��������п��������Ǳ�������������"},
	{"563452", "���ͳĹ����׽�������"},
	{"5634522", "��"},
	{"5634526", "�ͳ�"},
	{"56345265", "��"},
	{"56345232", "��"},
	{"56345233", "��"},
	{"56345234", "��"},
	{"563452345", "��"},
	{"56345242", "��"},
	{"5634525", "��"},
	{"563456", "����ȹ�����ǳ��ñ�����"},
	{"5634562", "��"},
	{"56345622", "ȹ"},
	{"56345626", "��"},
	{"56345624", "��"},
	{"563456245", "��"},
	{"5634564", "��"},
	{"56345643", "��"},
	{"5634565", "��"},
	{"56345656", "��"},
	{"56345655", "��"},
	{"563453", "��̻�β����Ӻ������ܲ���"},
	{"5634536", "̻�β����Ӻ������ܲ���"},
	{"56345362", "��"},
	{"563453622", "��"},
	{"5634536224", "��"},
	{"56345362246", "��"},
	{"563453623", "��"},
	{"56345364", "��"},
	{"5634533", "��"},
	{"5634535", "��"},
	{"56345354", "��"},
	{"563454", "�Ű����˸�������������ԣ��"},
	{"5634542", "�����˸�������������ԣ��"},
	{"5634546", "��"},
	{"56345465", "��"},
	{"5634543", "������"},
	{"56345436", "��"},
	{"56345433", "��"},
	{"5634544", "��"},
	{"56345444", "��"},
	{"5634545", "����ԣ��"},
	{"56345452", "��"},
	{"56345454", "ԣ"},
	{"56345455", "��"},
	{"563455", "������"},
	{"5634556", "��"},
	{"5634553", "��"},
	{"5634554", "����"},
	{"56345542", "��"},
	{"5635", "����������ף������»�������������������������������������������"},
	{"56352", "��������������������"},
	{"563522", "��"},
	{"5635224", "��"},
	{"563523", "������������"},
	{"5635232", "��"},
	{"56352323", "��"},
	{"5635236", "��"},
	{"5635233", "��"},
	{"56352336", "��"},
	{"563524", "��"},
	{"56356", "��»������"},
	{"563562", "»����"},
	{"5635626", "��"},
	{"5635623", "��"},
	{"563563", "��"},
	{"56353", "���������ף��"},
	{"563532", "��"},
	{"563536", "�����ף��"},
	{"5635362", "��"},
	{"56353623", "��"},
	{"56353624", "ף"},
	{"5635364", "��"},
	{"56354", "������ڽ��������������"},
	{"563546", "����ڽ��������������"},
	{"5635466", "��"},
	{"563543", "ڽ"},
	{"563544", "��"},
	{"563545", "��"},
	{"5635456", "��"},
	{"563552", "��"},
	{"563554", "��"},
	{"5635542", "��"},
	{"5635543", "��"},
	{"564", "�ϻ�����лѯѵ����ڿ�����ںڮ"},
	{"5642", "��������թ��ڷھ�û�"},
	{"564223", "����"},
	{"5642234", "��"},
	{"56426", "��ھթ��ڷ������"},
	{"56423", "թ��ڷ������"},
	{"564232", "ھ��ڷ"},
	{"5642324", "��ڷ"},
	{"564233", "��"},
	{"564234", "����"},
	{"5642345", "��"},
	{"5646", "��������ũ����ԩ��ѯ����ڿ�����ںڮ"},
	{"56462", "ڮ��������ں��ѯ���ũ��ԩ�ڿ��"},
	{"564623", "��������ں��ѯ���ũ��ԩ�ڿ��"},
	{"564624", "��"},
	{"5646244", "��"},
	{"564662", "��"},
	{"5646622", "ں"},
	{"564665", "��"},
	{"56463", "ѯ���ũ��ԩ�ڿ��"},
	{"564636", "��"},
	{"5646363", "ԩ"},
	{"56464", "ڿ"},
	{"564646", "�"},
	{"564643", "��"},
	{"564645", "ũ��"},
	{"5643", "��˭���ۺ׵�лѵ"},
	{"56432", "�ĵ�лѵ��˭����"},
	{"564323", "��"},
	{"564365", "л"},
	{"56433", "ѵ"},
	{"56434", "��"},
	{"56435", "˭"},
	{"564352", "��"},
	{"5643522", "��"},
	{"5644", "��ڸ�ߺ�"},
	{"56442", "ڸ"},
	{"564423", "��"},
	{"56445", "��"},
	{"5645", "��ڸ�ߺ���ҥ��ڹ����������ڹ��"},
	{"56452", "��ڹ����������ҥ����"},
	{"564522", "ڹ"},
	{"564523", "��"},
	{"56456", "��"},
	{"56454", "��"},
	{"564544", "��"},
	{"564545", "��"},
	{"56455", "��"},
	{"564554", "��"},
	{"5645544", "ҥ"},
	{"565", "֮����������ǫ����������"},
	{"5652", "��׻��������׻�����ذ���������"},
	{"56526", "�·ø�"},
	{"565264", "��"},
	{"5652644", "��"},
	{"56523", "׻����"},
	{"565236", "��"},
	{"5652464", "����"},
	{"565245", "��"},
	{"56525", "�������а�"},
	{"565254", "��"},
	{"5652543", "��"},
	{"5652545", "�а�"},
	{"56525456", "��"},
	{"5656", "ڻ����"},
	{"56562", "ڻ��"},
	{"565624", "��"},
	{"56565", "��"},
	{"5653", "��"},
	{"56536", "��"},
	{"5654", "��ڻ������������˵���ٱ���ǫ̸��"},
	{"56542", "��ǫ��������"},
	{"565426", "ǫ"},
	{"565423", "������"},
	{"5654233", "��"},
	{"5654234", "��"},
	{"5654245", "��"},
	{"565446", "˵̸"},
	{"565445", "̸"},
	{"56545", "����"},
	{"5655", "�Ĳ���"},
	{"56556", "��"},
	{"565564", "��"},
	{"53", "�մ������������������"},
	{"536", "����������������������"},
	{"5362", "���������������Ź�������"},
	{"53622", "��������"},
	{"536222", "��"},
	{"536226", "��"},
	{"536223", "��"},
	{"53626", "��"},
	{"53623", "���й�������������������"},
	{"536232", "��"},
	{"536236", "��"},
	{"5362365", "��"},
	{"536233", "��"},
	{"5362336", "��"},
	{"5362345", "��"},
	{"53623454", "��"},
	{"53624", "������"},
	{"536245", "��"},
	{"5362453", "��"},
	{"5362455", "��"},
	{"5366", "�״���"},
	{"53662", "��"},
	{"53666", "��"},
	{"53665", "��"},
	{"5363", "բ�������ּ���������բ����"},
	{"53636", "�ʼ�բ��������"},
	{"536362", "��"},
	{"5363622", "բ��������"},
	{"53636223", "��"},
	{"5363623", "������"},
	{"53636236", "��"},
	{"53636234", "��"},
	{"5364", "���������Ը��������ҷ�����"},
	{"53646", "��"},
	{"536463", "��"},
	{"5364643", "��"},
	{"53646536", "��"},
	{"536432", "��"},
	{"536436", "��"},
	{"53645", "��"},
	{"536455", "��"},
	{"5365", "�������������������ʲ��ֺ�����������"},
	{"53652", "����������"},
	{"536523", "��"},
	{"536524", "��"},
	{"5365246", "��"},
	{"5365245", "��"},
	{"53656", "����"},
	{"536565", "��"},
	{"53654", "�ڲ���"},
	{"536543", "��"},
	{"5365436", "��"},
	{"536552", "��"},
	{"54", "��������ǰ����������"},
	{"542", "����������������۰벢��֣��������������������˷���ϵ����������ٵ������������˸�"},
	{"5422", "��űŲ���Ǹ����ػ��������������������ƿƿǼǼȭȭȯȯ������������������"},
	{"54222", "��������Ǽ������������۷����������"},
	{"542223", "����۷"},
	{"5422235", "��"},
	{"54222354", "۷"},
	{"5422242", "��������������������"},
	{"5422246", "��������"},
	{"54222465", "��"},
	{"542224652", "��"},
	{"542224654", "��"},
	{"5422243", "������"},
	{"54222436", "��"},
	{"542224363", "��"},
	{"542224462", "��"},
	{"5422245", "����"},
	{"54222455", "��"},
	{"54223", "����������Ǽ�������"},
	{"542232", "��������Ǽ�������"},
	{"5422326", "��"},
	{"5422323", "��"},
	{"5422324", "��Ǽ"},
	{"54223246", "Ǽ"},
	{"5422325", "�۸����"},
	{"54223256", "��"},
	{"54223255", "���"},
	{"542232555", "��"},
	{"54224", "��������֣������ƿȭ�컿����ȯ"},
	{"542243", "��ƿ�б��ѹ��𻿾�֣ȯ��ȭ������"},
	{"5422432", "ƿ"},
	{"5422436", "��"},
	{"5422435", "��"},
	{"5422444", "��"},
	{"542245", "�ػ���֣ȯ��ȭ����"},
	{"5422452", "�𻿾�֣ȯ��ȭ������"},
	{"54224524", "��"},
	{"5422456", "��֣ȯ"},
	{"54224563", "֣"},
	{"54224564", "ȯ"},
	{"5422453", "��"},
	{"54224542", "ȭ"},
	{"54224546", "��"},
	{"5422455", "��"},
	{"54224556", "��"},
	{"5426", "�ȼ���Ǹ˷������������˷�������ϴȼ���Ǹ����"},
	{"54262", "��Ǹ�����˴�˷������"},
	{"542622", "Ǹ"},
	{"54266", "��"},
	{"542665", "��"},
	{"5426656", "��"},
	{"54266566", "��"},
	{"54263", "˷������"},
	{"542634", "��"},
	{"5426344", "��"},
	{"5426345", "��"},
	{"5423", "�������Դִ��Ϸ۷����������"},
	{"54232", "��"},
	{"54236", "ǰ����������������"},
	{"542362", "�����"},
	{"5423622", "��"},
	{"54236223", "��"},
	{"542364", "�����������"},
	{"5423646", "��"},
	{"54236462", "��"},
	{"542364622", "��"},
	{"5423646222", "��"},
	{"5423646225", "��"},
	{"54233", "��"},
	{"54234", "�׾������ѷ������Ŵ��"},
	{"542345", "�����������Ͼ������������������Ŵ��������ճ���ɷ��Ͳ�����������"},
	{"54234523", "��"},
	{"542345236", "��"},
	{"542345233", "��"},
	{"5423452336", "��"},
	{"542345242", "��"},
	{"542345245", "��"},
	{"54234525", "Ŵ"},
	{"5423456", "��������¦��������"},
	{"54234566", "��"},
	{"54234563", "��"},
	{"542345632", "��"},
	{"54234564", "¦"},
	{"542345642", "��"},
	{"542345644", "��"},
	{"54234565", "��"},
	{"542345656", "��"},
	{"5423453", "ճ�̴�"},
	{"54234536", "��"},
	{"542345363", "��"},
	{"5423454", "���������������׷�"},
	{"54234542", "��"},
	{"54234546", "��"},
	{"542345465", "��"},
	{"5423454653", "��"},
	{"54234543", "��"},
	{"542345436", "��"},
	{"5423454362", "��"},
	{"54234545", "��"},
	{"5423455", "���Ǵ������Ը�������"},
	{"54234552", "��"},
	{"542345524", "��"},
	{"542345525", "��"},
	{"542345562", "��"},
	{"542345565", "��"},
	{"54234554", "��"},
	{"542345542", "��"},
	{"54234555", "��"},
	{"5423455523", "��"},
	{"542345556", "��"},
	{"5424", "���������������������"},
	{"54246", "��"},
	{"54243", "�׵���"},
	{"542436", "��"},
	{"5424362", "��"},
	{"54245", "����"},
	{"542453", "��"},
	{"546", "�ܼ���Ǹ�ݴ���������"},
	{"5462", "����ݼ�����Ǹ"},
	{"54622", "��Ǹ"},
	{"54626", "���������"},
	{"546263", "��"},
	{"5462634", "��"},
	{"54665", "�ܴ���"},
	{"54634", "��"},
	{"5465", "Ϊ"},
	{"543", "Ѿ���ܵ�ǰ���޵������굱ױ�Ƴ����"},
	{"5436", "���ܵ�ǰ�޵��ּ��׼���Ƴ�����"},
	{"54362", "���ܵ�ǰ�޵�����"},
	{"543622", "��"},
	{"5436222", "��"},
	{"543623", "��"},
	{"543624", "��"},
	{"543625", "��"},
	{"54363", "�ֱױ��Ƴ�����"},
	{"543634", "��Ƴ�����"},
	{"5436345", "Ƴ"},
	{"54363454", "��"},
	{"543634542", "��"},
	{"5436345424", "��"},
	{"543635", "���"},
	{"5436354", "�"},
	{"54335", "��"},
	{"544", "���ӷ�����ú����ը��"},
	{"54452", "쿵ƾ�������"},
	{"544526", "��"},
	{"5445262", "��"},
	{"5445266", "��"},
	{"5445263", "��"},
	{"5445264", "��"},
	{"544523", "��ɱ�ú����"},
	{"5445232", "��"},
	{"5445236", "��"},
	{"54452364", "��"},
	{"5445233", "ú����"},
	{"54452332", "��"},
	{"54452336", "��"},
	{"544524", "�·���"},
	{"5445243", "��"},
	{"5445245", "��"},
	{"54456", "��Ȳ�������"},
	{"544562", "Ȳ"},
	{"5445624", "��"},
	{"544566", "�"},
	{"544565", "����"},
	{"5445652", "��"},
	{"54453", "�̺����������������"},
	{"544536", "���Ӿ���������"},
	{"5445362", "�������������"},
	{"54453622", "����"},
	{"544536225", "��"},
	{"54453623", "������"},
	{"544536232", "��"},
	{"544536236", "��"},
	{"54453624", "����"},
	{"5445363", "�Ӿ���"},
	{"54453636", "��"},
	{"544534", "��"},
	{"54454", "ը�ڻ��洶�Ʒ�����ȼ"},
	{"544546", "���Ʒ�����ȼ"},
	{"5445463", "��"},
	{"5445464", "��"},
	{"54454645", "��"},
	{"5445465", "�Ʒ�����ȼ"},
	{"54454652", "��"},
	{"54454656", "��"},
	{"54454653", "��"},
	{"54454655", "ȼ"},
	{"544543", "�ѻ�Ϩ����"},
	{"5445432", "��"},
	{"5445436", "��"},
	{"54454362", "Ϩ"},
	{"54454365", "��"},
	{"5445434", "��"},
	{"544545", "��ϩ������������"},
	{"5445452", "����������"},
	{"54454524", "ϩ"},
	{"5445456", "��"},
	{"54454542", "��"},
	{"54454546", "����"},
	{"5445455", "����"},
	{"54454554", "��"},
	{"54455", "�����ſ���"},
	{"544552", "��"},
	{"5445522", "��"},
	{"5445526", "��"},
	{"5445524", "��"},
	{"5445525", "��"},
	{"544556", "¯ɿ����"},
	{"5445562", "¯"},
	{"54455624", "ɿ"},
	{"544556243", "��"},
	{"544553", "��"},
	{"544554", "��������۰����"},
	{"5445542", "����۰����"},
	{"54455422", "��"},
	{"54455424", "��"},
	{"54455445", "��۰����"},
	{"544554456", "۰"},
	{"544554453", "��"},
	{"544554455", "��"},
	{"544555", "��������"},
	{"5445556", "��"},
	{"54455562", "��"},
	{"54455564", "��"},
	{"5445554", "��"},
	{"545", "������"},
	{"5456", "��"},
	{"5453", "��"},
	{"5455", "��"},
	{"55", "ѧû���ַ��ۺ������ⰸ"},
	{"552", "ע���Ӻ�������������������"},
	{"5522", "�����ӻ�Ǳ����Դ�䳱�������������Ǳ��������������������������������屺ӻ㽽Ž͡��й��տ����"},
	{"55222", "������������ǳĭ����Ǳ��"},
	{"552222", "����Ǳ��"},
	{"5522223", "��"},
	{"5522224", "����"},
	{"55222245", "��"},
	{"552226", "��ǳ"},
	{"5522264", "ǳ"},
	{"552223", "������ĭ"},
	{"5522232", "����"},
	{"55222323", "��"},
	{"5522234", "ĭ"},
	{"552224", "��Ǳ��"},
	{"5522245", "Ǳ"},
	{"55222456", "��"},
	{"55226", "��͡�����罽��"},
	{"552262", "��"},
	{"5522623", "��"},
	{"552263", "��"},
	{"552264", "��"},
	{"5522643", "��"},
	{"55223", "֭�����淨�۽�������侺�"},
	{"55223", "1������侺�"},
	{"552232", "����������"},
	{"5522322", "��"},
	{"5522326", "�淨��"},
	{"55223265", "��"},
	{"552232653", "��"},
	{"5522323", "��������"},
	{"55223236", "����"},
	{"552232362", "��"},
	{"5522323625", "��"},
	{"5522324", "���"},
	{"55223243", "�"},
	{"552236", "����ߺ���������Ư����̶������"},
	{"5522362", "�������̶����������"},
	{"55223622", "����"},
	{"552236223", "��"},
	{"55223626", "��"},
	{"55223623", "������"},
	{"552236233", "��"},
	{"5522362345", "���"},
	{"55223623454", "��"},
	{"5522363", "��Ư����̶"},
	{"55223633", "Ư����̶"},
	{"552236332", "����̶"},
	{"5522363322", "��"},
	{"5522363323", "̶"},
	{"5522364", "������"},
	{"55223646", "��"},
	{"5522365", "��"},
	{"552233", "������տ��й����������ݹ��ᳱ��嫺�"},
	{"5522332", "�����տ��"},
	{"55223322", "��"},
	{"552233222", "��"},
	{"5522332224", "�"},
	{"55223322245", "տ"},
	{"552233222454", "��"},
	{"55223326", "й��"},
	{"552233262", "��"},
	{"55223323", "����"},
	{"552233236", "��"},
	{"55223324", "�����"},
	{"552233245", "��"},
	{"5522332455", "��"},
	{"5522336", "���ᳱ��嫺�"},
	{"55223362", "��"},
	{"552233622", "��"},
	{"5522336223", "���"},
	{"55223362234", "�"},
	{"552233624", "��"},
	{"5522333", "Į������"},
	{"55223336", "��"},
	{"552233364", "��"},
	{"55223335", "��"},
	{"5522335", "������"},
	{"55223356", "��"},
	{"552233566", "��"},
	{"552234", "��������������������"},
	{"5522345", "������������������"},
	{"55223452", "��"},
	{"552234523", "����"},
	{"55223452345", "��"},
	{"55223453", "����"},
	{"55223454", "��������"},
	{"552234545", "��"},
	{"5522345456", "��"},
	{"55223455", "��"},
	{"552235", "��"},
	{"55224", "��������������ԴŽ��̭��"},
	{"552242", "��Ž��̭�����"},
	{"5522423", "��"},
	{"552246", "�����"},
	{"5522464", "��"},
	{"5522465", "�"},
	{"552243", "���"},
	{"5522436", "��"},
	{"552244", "��Դ"},
	{"5522443", "Դ"},
	{"552245", "Ž��̭��"},
	{"5522453", "��"},
	{"5522455", "̭��"},
	{"55224554", "��"},
	{"55225", "����"},
	{"552256", "�"},
	{"552254", "��"},
	{"5522542", "�"},
	{"5526", "���������©������ӿ��������ɬ̲Ϋ���������������媳�"},
	{"55262", "��䱸����Ͻ��������Ƿ���Ѵ����©��������"},
	{"552622", "����©��������"},
	{"5526222", "�"},
	{"5526226", "��"},
	{"55262265", "��"},
	{"5526223", "��"},
	{"5526225", "��"},
	{"552626", "������"},
	{"5526262", "��"},
	{"5526266", "��"},
	{"5526264", "�Ƿ�"},
	{"55262643", "��"},
	{"5526265", "����"},
	{"552623", "Ѵ��"},
	{"5526233", "��"},
	{"552624", "��©��������"},
	{"5526242", "©"},
	{"5526246", "��"},
	{"5526243", "��"},
	{"5526244", "��"},
	{"55262446", "��"},
	{"55266", "Ϋ�����̼���"},
	{"552662", "Ϋ"},
	{"552666", "��"},
	{"552664", "��"},
	{"5526644", "��"},
	{"5526645", "��"},
	{"552665", "��"},
	{"55263", "�س����"},
	{"552636", "��"},
	{"5526364", "��"},
	{"552634", "��"},
	{"55264", "���Ⱦ������������ɬ"},
	{"552642", "���Ⱦɬ��"},
	{"5526423", "�"},
	{"55264234", "Ⱦ"},
	{"552646", "��"},
	{"552643", "��"},
	{"5526436", "��"},
	{"552644", "����"},
	{"5526445", "��"},
	{"552645", "ɬ��"},
	{"5526455", "��"},
	{"55265", "�����������ӿ̲�ο���"},
	{"552652", "��̲������ӿ"},
	{"5526526", "�"},
	{"5526523", "��"},
	{"5526524", "��"},
	{"552653", "��ӿ"},
	{"5526536", "ӿ"},
	{"5526543", "̲����"},
	{"5526544", "��"},
	{"5526545", "��"},
	{"552655", "��"},
	{"5523", "�����콦��ɳ��ʪ�����趴�Ի�������º����ʪ��μ������մ�����������������"},
	{"55232", "�����������մ����"},
	{"552322", "�����մ����"},
	{"552326", "������"},
	{"55232644", "��"},
	{"552323", "���"},
	{"5523232", "��"},
	{"5523236", "մ����"},
	{"55232362", "��"},
	{"55232364", "�"},
	{"55232465", "�"},
	{"55236", "����������������������ʪ���"},
	{"552362", "����������ºμ���"},
	{"5523622", "��������������ʪ"},
	{"55236222", "���������"},
	{"552362223", "��"},
	{"5523622233", "��"},
	{"5523622234", "��"},
	{"5523622243", "�"},
	{"55236226", "���"},
	{"552362265", "��"},
	{"55236223", "����ʪ"},
	{"552362236", "��"},
	{"552362233", "ʪ"},
	{"55236224", "��"},
	{"55236225", "�"},
	{"5523623", "������μº��Ƕ�������"},
	{"55236232", "������������"},
	{"552362326", "��"},
	{"552362323", "ºμ��"},
	{"5523623236", "μ��"},
	{"55236232364", "��"},
	{"552362324", "�"},
	{"552362325", "��"},
	{"55236236", "�����������"},
	{"552362362", "�������"},
	{"5523623622", "��"},
	{"5523623623", "����"},
	{"55236236235", "��"},
	{"552362364", "��"},
	{"55236233", "墺�"},
	{"552362336", "��"},
	{"55236234", "��"},
	{"5523624", "�����������"},
	{"55236245", "���"},
	{"552366", "��"},
	{"552363", "������"},
	{"5523632", "��"},
	{"5523636", "�"},
	{"5523634", "�"},
	{"5523646", "���⽦"},
	{"5523645", "��"},
	{"55236453", "��"},
	{"55233", "��"},
	{"55234", "ɳ�������"},
	{"552345", "�������"},
	{"5523454", "�����"},
	{"55234544", "��"},
	{"55234545", "��"},
	{"55235", "����"},
	{"552354", "��"},
	{"5524", "�ĸ���������Ⱦ��ͿϪ�����ƻ���������Ǣ����������ԡ�����������������Ȳ�����"},
	{"55242", "������ຣ����ϴ������������"},
	{"552422", "���ຣ��������"},
	{"5524223", "�"},
	{"5524224", "��"},
	{"552426", "�ຣ��"},
	{"5524266", "��"},
	{"5524263", "��"},
	{"552423", "��ϴ������"},
	{"5524232", "ϴ"},
	{"5524233", "��"},
	{"5524234", "��"},
	{"55242345", "��"},
	{"5524245", "����"},
	{"55242454", "��"},
	{"552425", "��"},
	{"55246", "�����������û�������������������ϫ䮵���"},
	{"552462", "�������������ϫ䮵���"},
	{"5524623", "��"},
	{"5524624", "�"},
	{"552466", "������û��"},
	{"5524664", "����"},
	{"55246645", "��"},
	{"5524665", "û��"},
	{"552463", "�������"},
	{"5524636", "�"},
	{"55246362", "��"},
	{"552463624", "��"},
	{"55246363", "�"},
	{"552464", "����������"},
	{"5524642", "��"},
	{"55246424", "��"},
	{"5524646", "��"},
	{"5524645", "��"},
	{"552465", "ϫ䮵���"},
	{"5524652", "�"},
	{"55246526", "��"},
	{"5524656", "��"},
	{"55243", "����亲���һ���娼�䪰��"},
	{"552432", "����娼�䪰�"},
	{"5524323", "���"},
	{"55243232", "�"},
	{"552436", "�������娼�䪰�"},
	{"5524362", "�����娼�䪰�"},
	{"55243622", "��"},
	{"552436222", "��"},
	{"5524362223", "�"},
	{"552436225", "��"},
	{"5524363", "�"},
	{"5524365", "��"},
	{"552433", "�"},
	{"552435", "��"},
	{"55244", "����"},
	{"552444", "��"},
	{"55245", "ͷͿ������Ǣ��"},
	{"552452", "ͿǢ�������������"},
	{"5524522", "�����"},
	{"55245226", "�"},
	{"55245223", "��"},
	{"5524526", "�"},
	{"5524523", "Ǣ��"},
	{"55245236", "��"},
	{"5524524", "�����"},
	{"55245243", "�"},
	{"5524525", "��"},
	{"552456", "���ڷ��Է�"},
	{"5524563", "��"},
	{"5524564", "����"},
	{"55245643", "��"},
	{"5524565", "��"},
	{"552454", "Ԩ������ԡ"},
	{"5524542", "��"},
	{"5524546", "��"},
	{"5524545", "��ԡ"},
	{"55245453", "ԡ"},
	{"552455", "����Ϫ����"},
	{"5524554", "����Ϫ��"},
	{"55245546", "Ϫ"},
	{"55245544", "����"},
	{"552455443", "��"},
	{"5525", "���ζɹ�����Ũ����䯴��θ�����������к����ע����������̳���Ţ��������������"},
	{"55252", "ע������ٳ�����"},
	{"552522", "ע������"},
	{"552526", "������ٳ�����"},
	{"5525263", "�"},
	{"5525264", "����"},
	{"55252644", "��"},
	{"5525265", "������"},
	{"55252654", "����"},
	{"552526543", "��"},
	{"552523", "��������"},
	{"5525236", "��"},
	{"55252363", "�"},
	{"55252334", "����"},
	{"552523345", "��"},
	{"5525235", "��"},
	{"552524", "����������Һ������奼ô�"},
	{"5525246", "��������"},
	{"55252462", "��"},
	{"55252463", "��"},
	{"55252464", "��"},
	{"5525243", "Һ"},
	{"5525245", "������奼ô�"},
	{"55252456", "���"},
	{"552524565", "��"},
	{"55252453", "�"},
	{"55252454", "奼ô�"},
	{"552524543", "��"},
	{"552524545", "��"},
	{"552525", "������������"},
	{"5525254", "����������"},
	{"55252542", "������"},
	{"552525423", "����"},
	{"5525254236", "��"},
	{"55252543", "��"},
	{"55252545", "��"},
	{"55256", "�����к�뻦Ӿ�����"},
	{"552562", "�к�뻦"},
	{"5525626", "к��"},
	{"55256262", "��"},
	{"5525624", "��"},
	{"552566", "Ӿ"},
	{"552563", "��"},
	{"552564", "����Ũ��"},
	{"5525646", "��Ũ"},
	{"55256464", "Ũ"},
	{"5525645", "��"},
	{"552565", "����"},
	{"5525655", "��"},
	{"55253", "������"},
	{"552536", "��"},
	{"5525363", "��"},
	{"55254", "����������������鵭��"},
	{"552542", "��������鵭����"},
	{"5525422", "��"},
	{"5525426", "����"},
	{"55254263", "��"},
	{"5525423", "���"},
	{"55254234", "�"},
	{"5525424", "��"},
	{"552546", "��"},
	{"552544", "��"},
	{"552545", "��"},
	{"55255", "��Ţ������������������"},
	{"552556", "Ţ����������"},
	{"5525562", "����������"},
	{"55255623", "����"},
	{"552556236", "��"},
	{"5525566", "��"},
	{"5525563", "��"},
	{"55255646", "������"},
	{"55255643", "��"},
	{"55255645", "��"},
	{"5525565", "��"},
	{"556", "�����ҳ踻���������������������������ʵ��������������¼Ŀ�������庹��"},
	{"5562", "���ں��կ���������彺�"},
	{"55622", "����������彺�"},
	{"556226", "����"},
	{"5562264", "��"},
	{"556223", "���"},
	{"5562232", "�"},
	{"55622325", "��"},
	{"5562233", "կ���������彺�"},
	{"55622332", "����彺����"},
	{"556223324", "�������彺�"},
	{"5562233245", "������彺�"},
	{"55622332453", "��"},
	{"55622332454", "�"},
	{"55622332455", "��彺�"},
	{"556223324552", "�"},
	{"556223324555", "��"},
	{"556224", "���"},
	{"5562246", "��"},
	{"55626", "��������"},
	{"556262", "����į����"},
	{"556265", "����"},
	{"5562652", "��"},
	{"55623", "�������¸�į����"},
	{"556236", "�����¸�"},
	{"5562362", "��"},
	{"55623623", "��"},
	{"556236236", "��"},
	{"556233", "į��"},
	{"5562333", "��"},
	{"556234", "��"},
	{"556242", "巼Һ��嶳��ļ�"},
	{"556246", "�Һ�"},
	{"5562465", "��"},
	{"556243", "�嶳�"},
	{"5562436", "�"},
	{"556244", "��"},
	{"556245", "���"},
	{"5562455", "�"},
	{"5566", "���������"},
	{"55662", "��"},
	{"556662", "��"},
	{"55663", "�"},
	{"55664", "峰���"},
	{"556642", "��"},
	{"5566422", "��"},
	{"55665", "��"},
	{"5563", "���ټ�����������Ԣ�����"},
	{"55632", "�Ź�����Ԣ�湬��"},
	{"55636", "�˹�����Ԣ���湬�����"},
	{"556362", "������Ԣ�湬��"},
	{"5563622", "��"},
	{"55636223", "��Ԣ"},
	{"556362233", "Ԣ"},
	{"5563626", "��"},
	{"5563623", "�湬"},
	{"55636236", "��"},
	{"5563624", "��"},
	{"556363", "�"},
	{"556364", "��"},
	{"55635", "����"},
	{"556354", "��"},
	{"5564", "���촰��Ϳ�������ͻ���Ѿ��Ϳ�������խ���������������"},
	{"55642", "��լ"},
	{"556426", "լ"},
	{"55646", "������Ͷ��"},
	{"556465", "����Ͷ��"},
	{"5564656", "��"},
	{"5564653", "��"},
	{"55646536", "��"},
	{"5564655", "��"},
	{"55643", "����"},
	{"556432", "��"},
	{"55645", "Ѩ������Ͽ����ͻ��"},
	{"556452", "���վ��ͻ"},
	{"5564526", "�����"},
	{"55645263", "�"},
	{"55645265", "��"},
	{"5564523", "�վ��ͻ��"},
	{"55645236", "���"},
	{"556452365", "�"},
	{"5564524", "ͻ"},
	{"556456", "�����������"},
	{"5564562", "��"},
	{"55645624", "��"},
	{"5564566", "�"},
	{"5564563", "��"},
	{"5564564", "����"},
	{"556453", "������"},
	{"5564536", "������"},
	{"55645362", "��"},
	{"55645363", "��"},
	{"556454", "��Ҥխ��񶴰�������"},
	{"5564542", "Ҥխ��񶴰�������"},
	{"55645423", "խ"},
	{"5564546", "���"},
	{"55645465", "�"},
	{"5564543", "��"},
	{"5564544", "��"},
	{"5564545", "�����"},
	{"55645452", "�"},
	{"55645456", "�"},
	{"55645453", "��"},
	{"556455", "�����"},
	{"5564554", "��"},
	{"55645542", "��"},
	{"5565", "ʵ������������"},
	{"55652", "��"},
	{"55656", "�������"},
	{"556565", "��"},
	{"5565655", "�"},
	{"55654", "��"},
	{"55655", "ʵ"},
	{"553", "�Ѷ��������������������ϧ������»�����㫲���ų������ߺ�������������"},
	{"5532", "��ߺ����ų������ϧ�Ƕ������"},
	{"553226", "��"},
	{"553223", "���"},
	{"5532232", "��"},
	{"553224", "��"},
	{"553225", "�"},
	{"55326", "����"},
	{"553265", "��"},
	{"55323", "��������㬺��������"},
	{"553232", "���������"},
	{"5532323", "����"},
	{"55323233", "��"},
	{"5532325", "�"},
	{"553236", "���������"},
	{"5532362", "�����"},
	{"55323623", "���"},
	{"553236234", "��"},
	{"5532365", "��"},
	{"553233", "��ϧ�����¶���"},
	{"5532332", "��ϧ���¶���"},
	{"5532336", "����"},
	{"55323362", "��"},
	{"5532333", "��"},
	{"5532334", "��"},
	{"5532335", "��"},
	{"553234", "����"},
	{"5532345", "��"},
	{"553235", "�"},
	{"553242", "�躶���ǲ�"},
	{"5532423", "��"},
	{"5532424", "��"},
	{"553246", "��"},
	{"553243", "����"},
	{"5532435", "��"},
	{"553245", "���"},
	{"5532454", "��"},
	{"55325", "ų��"},
	{"553254", "��"},
	{"5536", "㪲ҹֹߺ޿������������������������������ߺ޿�"},
	{"55362", "�޿���������"},
	{"553622", "��"},
	{"553626", "��"},
	{"553623", "��"},
	{"553624", "����"},
	{"5536245", "��"},
	{"55366", "��"},
	{"55364", "����"},
	{"553643", "��"},
	{"55365", "���ֲ����"},
	{"553652", "��"},
	{"5536524", "��"},
	{"553653", "��"},
	{"553654", "�"},
	{"5533", "�����о������������������������㳻��������㶵���������������"},
	{"55332", "㭵�"},
	{"553323", "��"},
	{"55336", "�򺷾�������������㴶�����"},
	{"553362", "�򺷾������"},
	{"5533622", "����"},
	{"55336222", "���"},
	{"553362223", "�"},
	{"55336223", "���"},
	{"553362236", "��"},
	{"55336224", "����"},
	{"553362246", "��"},
	{"55336225", "�"},
	{"5533626", "�"},
	{"5533623", "��㴶���"},
	{"55336232", "�"},
	{"55336236", "���"},
	{"553362362", "�"},
	{"55336234", "�"},
	{"5533624", "��"},
	{"553363", "�������"},
	{"5533636", "��"},
	{"5533633", "�"},
	{"553364", "��"},
	{"553365", "�"},
	{"55333", "�"},
	{"55335", "�����"},
	{"553354", "��"},
	{"5533543", "�"},
	{"5534", "�̻�������ǡ��Ω��㾻̼���ǡ��Ω����������������и������û�������������"},
	{"55342", "�����Ի�����������"},
	{"553422", "����"},
	{"55342232", "��"},
	{"553426", "��"},
	{"5534265", "��"},
	{"553423", "���������"},
	{"5534232", "��"},
	{"5534236", "�"},
	{"5534233", "��"},
	{"5534234", "���"},
	{"55342345", "�"},
	{"55346", "�����и���»�����Ω���ǡ��������"},
	{"553462", "�����Ω���ǡ��������"},
	{"553463", "����"},
	{"5534633", "��"},
	{"553464", "и�"},
	{"5534644", "�"},
	{"553465", "�"},
	{"55343", "��㾻�����Ω"},
	{"553436", "������"},
	{"5534362", "��"},
	{"5534365", "��"},
	{"553435", "Ω�"},
	{"5534352", "�"},
	{"55344", "��"},
	{"55345", "��ǡ������"},
	{"553452", "��ǡ"},
	{"553456", "����"},
	{"5534565", "��"},
	{"5535", "�����뿶æ�������������㿳�æ���õ������㩾����������"},
	{"55352", "æ��������㼵�����"},
	{"553523", "������"},
	{"5535236", "��"},
	{"5535235", "��"},
	{"553524", "��㼵�����"},
	{"5535246", "�"},
	{"553524323", "��"},
	{"5535245", "���"},
	{"55352454", "�"},
	{"553525", "�"},
	{"55356", "㢳�"},
	{"553564", "��"},
	{"55353", "��"},
	{"55354", "�㩵�������"},
	{"553546", "�"},
	{"553543", "������"},
	{"5535436", "����"},
	{"55354363", "��"},
	{"55355", "��"},
	{"554", "�پ���ѧ�������"},
	{"5542", "�˾�������������"},
	{"55424", "�˾�������������"},
	{"554245", "�˾�������������"},
	{"5542455", "��"},
	{"5545", "������ѧ��׾�������"},
	{"55456", "��ѧ���������"},
	{"554566", "ѧ��"},
	{"5545666", "��"},
	{"554563", "��"},
	{"554564", "���"},
	{"5545646", "��"},
	{"55454", "˸"},
	{"5555", "��"},
	{"*", PY_mb_fuhao},
	{NULL, NULL}	
};



const THanZiThink pThink[] =
{
	{"��", "��ѽӴ"},
	{"��", "����ĸ��������̽������ﱦ�����Ƕ��ɹ�����è����ѽ"},
	{"��", "��"},
	{"��", "�򶷶�����������������"},
	{"��", "ѽӴ"},
	{"��", "��̾��Ӵ"},
	{"��", "����ǵ����и�躿�ź������п�������������������˼��̾��Թ������"},
	{"��", "��֢��"},
	{"��", "Ȼ����"},
	{"��", "�ʽ���ǽ����С"},
	{"��", "����"},
	{"��", "�ſ���������"},
	{"��", "ϧ��Ľ��Ӻ޻����ù��Ŵ������ƳԵ��ว�˼�������������������Ů������Ⱥ����������Һ��Ӥ�����"},
	{"��", "��·"},
	{"��", "����ɽ��"},
	{"��", "��ˮ"},
	{"��", "ȫ��װ��Ȼο�ȿ��־��Ҿӻ��İ�ȷ��߱���ﶨ���ٷŸ����ü�����½������������ƽ��������˯˳̥̩ΣϢ��������Ъ����ӪԴ��������"},
	{"��", "��"},
	{"��", "�ƻ�������ť��Ħʱ������˵��ѹ������ס��"},
	{"��", "�������ص�ʾ����������潳����ط��ù������ź컨���ǽ���������ɫɱ������̽ϲ������"},
	{"��", "��Ȼ��ͷ"},
	{"��", "��"},
	{"��", "�巢����������������ֵ�����"},
	{"��", "��"},
	{"��", "��Ȼ����"},
	{"��", "Ȼ˹˾"},
	{"��", "�۴�����͹����"},
	{"��", "��"},
	{"��", "��ҹ��ҩ"},
	{"��", "��"},
	{"��", "��Ȼ�����ӹ���"},
	{"��", "����"},
	{"��", "�˵����������"},
	{"��", "������"},
	{"��", "����ɥ"},
	{"��", "�ٽ�"},
	{"��", "����"},
	{"��", "Ų̊"},
	{"��", "����"},
	{"��", "��һ���Խ챦���ɴ󷽸���ɽǽ侰��·��ǧʱ����������"},
	{"��", "����"},
	{"��", "����ͱն���������ɽʿ������"},
	{"��", "�����ߺӲݳ���ȡ�⽣��ȥɽ����Ӫ"},
	{"��", "ɽ��ˮ����"},
	{"��", "����"},
	{"��", "Ϸ���ַ�����ؾ�����ͷ������"},
	{"��", "��"},
	{"��", "������ҵȨռ����"},
	{"��", "�����ݾͿ�������������"},
	{"��", "��"},
	{"��", "��ֽ������ǳԷ��ٰ��װ߰�岼�˳մ�㶡������۹��ǹ������ҽ𾻾ƾ���¶��æè������ĭƤ������ɫɰʥ����ˮ˵��������ѩ�������������������������������"},
	{"��", "��ľ������"},
	{"��", "���ºϻ��Ѳ��ҿ����ջ�����ֹ��ƿ���������������ɫ��˳̬����Ԫ����"},
	{"��", "�źþƲ����ɳ�������̯����Ūƽ�ɿ�����������"},
	{"��", "���˻����������󱱱ʸ���¶��������"},
	{"��", "����÷�ʦ�����м�����������������л���"},
	{"��", "��"},
	{"��", "�װ��������������"},
	{"��", "�𼶳���������׷��̻��ʦ��ͷ������"},
	{"��", "��Ǩ�������߳���������Ū"},
	{"��", "�ɻ���"},
	{"��", "����"},
	{"��", "��������������"},
	{"��", "�����ı�ʽ���鳵���ʶ������Ῠ��������Ѽ��������ܽ"},
	{"��", "��Ȩ��������ģ��ʽ˰ͼ"},
	{"��", "��װ�ɿ�����"},
	{"��", "���ﳪ��������ʳ��ͬ"},
	{"��", "����"},
	{"��", "Ĥ"},
	{"��", "��Ʊ;��·�۳�ҹ�ڱ߰ٵ�������ǽؾ�������ɽ��������������Բ��"},
	{"��", "�������װ����ɹ���ѧ���౨"},
	{"��", "����ס"},
	{"��", "����"},
	{"��", "��æ�ְ������Ĺ������ǻ����Ӷ��"},
	{"��", "��ǻ"},
	{"��", "��ʾ����"},
	{"��", "������"},
	{"��", "�����˼ܽ�Ʊ�ϸ���ס"},
	{"��", "���Ǵ�������"},
	{"��", "����"},
	{"��", "������"},
	{"��", "����"},
	{"��", "����"},
	{"��", "���ݺ����������³�����װ��Χ"},
	{"��", "������"},
	{"��", "��Ӳ�"},
	{"��", "���Ӳ�"},
	{"��", "���������ָ������ȹܹ�������Ƥ����ͷ������������"},
	{"��", "�ά������"},
	{"��", "Ƥȥ�µ��Ὺ������"},
	{"��", "������ֽƬ��Ƴʹ�����Ĥĺ��ɴ����"},
	{"��", "����"},
	{"��", "�����عܻ���������֤�ܽ������Ͷ��������Ѽ��ۼݾ���������ķĸůȫɽ��˰��̥��������������ֵס��"},
	{"��", "��"},
	{"��", "�ͺͳ�����ůʳ����"},
	{"��", "�������ﱦ�س��ص����ص��ֺż���������������ɲɽʯ������λ����Ԫ����"},
	{"��", "Ǹ��Թס�����ź��޲��涨��ͷ��"},
	{"��", "��ʧ����Ӧ�ϳ갸���Ŵ�������ʳ�����ֽ���𵥵��˷���عݹ��۽ݽ����������Ļ��������ʱ��˰��ͯͷ��ϲ��Чҵ��Թ��ֵװ"},
	{"��", "����¶���з��в��������������������ŭŰͶͽ������������"},
	{"��", "����Ƥ��"},
	{"��", "��"},
	{"��", "����������ͷը��������"},
	{"��", "�Ӹ�"},
	{"��", "������"},
	{"��", "ʹ���簧���˷߹۵������������̾Ը׳����"},
	{"��", "�ɼ�����΢��"},
	{"��", "�����������氲���ߴ󵺶����۹�������������·����ŷƽ����������γκ��������԰ԼԽ��ڤ��"},
	{"��", "������"},
	{"��", "���Ѱ�Ӱ���ź��ż���������������ʱ����������"},
	{"��", "��������ĸ"},
	{"��", "�м�����������"},
	{"��", "�����η���ע����ûļ���ȡ��̥������ս"},
	{"��", "�������Ӹ溦������������ɱ����͵��ռ"},
	{"��", "���򲨳���кӿ�ߴܱ��Ÿ���æ��ɥʻ��"},
	{"��", "����"},
	{"��", "���˿�ɫ��ʡ�����������������������簸���������ε��طָø۹�����������żͼҽ�������ĩ����ƱǮȻʦ������λϢϪУн��������ӦԭԴԺְּ����ٺ"},
	{"��", "��������׾"},
	{"��", "��������̮��"},
	{"��", "����"},
	{"��", "����"},
	{"��", "������"},
	{"��", "�������߳��ͽ�����ʹ����"},
	{"��", "�����Ӹ��������ǻ��ˮ��Ѫ����"},
	{"��", "�������������ָ߻��ۼ��������ʶԶ�����ƴ������������Ϊ��������ֵ��������"},
	{"��", "����ª����������"},
	{"��", "�ԼǼ�����ī����˷���˸�����ܼ���¼��˳ͦͲͷ������������ս��ֱ"},
	{"��", "�˵õ�ʱ��"},
	{"��", "��������ɫˮ̶Ѫ����"},
	{"��", "��"},
	{"��", "ҵ�ھ���"},
	{"��", "��"},
	{"��", "ֵ��"},
	{"��", "������"},
	{"��", "Ŀ������Ļ�ϻᾭ��·������������"},
	{"��", "��������"},
	{"��", "���˺�"},
	{"��", "����ҪȻʤ�ܱ��ö�����������"},
	{"��", "��аҥ֧"},
	{"��", "ֽ�����ƻ�������¯"},
	{"��", "������"},
	{"��", "��������约���������˰��а��ծ"},
	{"��", "��"},
	{"��", "������ߴ���̢����"},
	{"��", "���羳�����ؼʿ��������϶�������ԵԶ������"},
	{"��", "������̺������޼���簲�����¼Ŀ�ε���������������������Ϊίдӡ������֯��׫��"},
	{"��", "��������ְֵ"},
	{"��", "��ƽ"},
	{"��", "���ڲͳ�����������������ñ��������������Я������װ"},
	{"��", "��ɫ��������������ѹ�úò����ɳ��������̷�����ʺں��ûؽ��ھ���������������ůǨ��������̬����ͨΪζλ����С��������������"},
	{"��", "��"},
	{"��", "���������ɫʶα����"},
	{"��", "��֤�ײ��ųƽ�������"},
	{"��", "��"},
	{"��", "�ز�����"},
	{"��", "׼����־�񱾱��߳��Ķ��˸͸߹��żǼ�������ǩǹʶʾ��������ע"},
	{"��", "��"},
	{"��", "����׳"},
	{"��", "ʾ�������ݸ���׵ܸ繦��˾�����¶���ò�㵥��Ƥ����ɩ����̬�������������"},
	{"��", "����"},
	{"��", "�˺���˵�������ƴ����Ķ��ܹݹ��Ž鿴������Ť������ҵԺ������"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��Σ��"},
	{"��", "��"},
	{"��", "�ݺ�����"},
	{"��", "�ݴӵù�������ʿ����"},
	{"��", "��"},
	{"��", "Ȩ����ӪԱ���������ҽ�������Ʀ����ʿ����Դ������"},
	{"��", "ѩ�������ˮ˪�����궳�����������㶾�������ӻ������ɽ����̿Ь������"},
	{"��", "����"},
	{"��", "���г���ֱ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "���˶���ʹ��Ժ֢������������������洲���ݶ�����ʺſ�ýħʷ����̬����Σ������ԭԴ��״�"},
	{"��", "�Ǽ粻����淢�����ٰ���������������������δ����Ҫ��������ת"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��ӳ�ַ��ͽ�Ū�±���"},
	{"��", "�ſ����ͨ����������Ū������"},
	{"��", "����Ь�����޳����ζ������ȹ�Ӽ�������˹����"},
	{"��", "��ѧʿ���ɴ󵼵ð�����ȡʶ������"},
	{"��", "������Ȼ��"},
	{"��", "������"},
	{"��", "���ֶ�������ĸ����"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��λ"},
	{"��", "�⴬����"},
	{"��", "�����ɱʳ��׽"},
	{"��", "��"},
	{"��", "������"},
	{"��", "��������ϰƷ�ȿ���Ѫҩ�챨�ֶ����̷������׽�����©��Ʊȱ����̥У������ע׺׾����"},
	{"��", "���ܿ�֪����������ͬ�����ܺϵõ����ܱ��ȱر�䳩�ɳݳ�������������ȶ������˶Զ෦�������ַ�����øʸҹ����˹عܹ������ͻἰ�üƼѼ������������þоپ�����Ͽ�����������������æ����������ƽǰ������Ȼ����������������ʤʧʱʵʶʹ��������ͣͨ������Ωη������Ϣϧ����������ТФим��������������ѷ��Ҫһ������������Ӧ������Զ����������ֹֻ������ס׼�"},
	{"��", "��������Ь��������ö������������϶������ƥ��ʩʲ������չ��"},
	{"��", "���в��ı�������ǹ��̬��"},
	{"��", "�������"},
	{"��", "���׷ݶӳ�λ�¼����ֻἶ����������ί��Ա��"},
	{"��", "���ߵ�����ȥ������ϴҩ��"},
	{"��", "�������г����ȼ���ȭ"},
	{"��", "�����ж���������Ա"},
	{"��", "����"},
	{"��", "��ò�ܸɿ�����Ů����ʶ��˼ѧ��������"},
	{"��", "������︻����·���˳�������羭��ó��Ȩ��˰��Դ��"},
	{"��", "��ȡ��"},
	{"��", "��̤"},
	{"��", "�෥��⼯�����¼ú��ů��д������ժ��ߢ"},
	{"��", "ɫ���ӡ���ջ��ʳ��ɴ����ƶ��Ի���������Ʊ����������ͷϼ��"},
	{"��", "�г��������ض��Ϲݼ�����ţũ����ɫʽ��ѼҶ��԰����"},
	{"��", "��"},
	{"��", "��������ѹݻ�߳�ȯ��"},
	{"��", "�ӹ۾�����չѡ����ݰ뿴�������ı��������͸����ԤԺ������ս��������"},
	{"��", "�����ɣɳʳ˿Ӽ"},
	{"��", "���ϱ����δ�˸����������ֿ�������ŰƷ��ȱɱ����м������������"},
	{"��", "��"},
	{"��", "����ʹ���ذװܵ��������о�����ɱ��״��"},
	{"��", "��"},
	{"��", "�����ϲԴ亣����ãȻɽ����Ӭ�"},
	{"��", "�׷���λ"},
	{"��", "��ɣ��"},
	{"��", "���ٻʿ�����"},
	{"��", "��������������Ʒ��������˽��ҽ��׾��"},
	{"��", "���İ쳡�ֵ�����������ǹ��������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��ԭ����ֽЬҩ�������ݳ����Զѷ��������������çñ��ľ����Ƥƺǩ����ͼ��Ϻ��Լ��ݮ��"},
	{"��", "��"},
	{"��", "���Զ�������ʿӦ"},
	{"��", "��߶�����Ŀ����˯������"},
	{"��", "����ҳ��"},
	{"��", "���������ֳ������������ʱ��"},
	{"��", "�������ε�����"},
	{"��", "�����������ӻ������ӿ���������ͷͼ������ҳ֦��"},
	{"��", "��·������"},
	{"��", "Ҷ�����׵㷹���ݺ�������¥¯����ˮ��שׯ��"},
	{"��", "������������֤����ѯ�⵽�챨����������Ըں˻񼩼ۼ����������������������ɱ��ʵ��˰��ѰѶ������"},
	{"��", "��"},
	{"��", "�þ���"},
	{"��", "����·��"},
	{"��", "��ش��ȵ��۾����ǲ��ʹ��������"},
	{"��", "��"},
	{"��", "�ֳɳ������ַ�ٽ���迪Ǩȥɢϴ��ж��"},
	{"��", "���Ͳݺ̺�������"},
	{"��", "��"},
	{"��", "���ͼ���"},
	{"��", "�ͺϼ���"},
	{"��", "������"},
	{"��", "��������"},
	{"��", "��"},
	{"��", "���Ž�������������ס"},
	{"��", "��"},
	{"��", "Ʒҵ��ٿƴ��ض��������������ǯǰ��Ȩ��������������ֵ"},
	{"��", "����������"},
	{"��", "����������"},
	{"��", "������¡��ƽʢ��"},
	{"��", "���"},
	{"��", "�غ������ݹ�Ǿ������ⳤԺվ����"},
	{"��", "����"},
	{"��", "�ù��������������������걸���·������ƽ��������ʶ������̬ί������ספ"},
	{"��", "�ڽ�Զƪ;�ȶ̳ǳɳ�ʹ���ױ���������������õʵѷ����𹤹ٺ��Ӻ绰�ٽ������ÿտ������������ì����Ů����������������ɳ��ʯ������̸̾����������������������������"},
	{"��", "��������ծ"},
	{"��", "��θ�װ�����"},
	{"��", "��������ҷ�����������ʷַ��"},
	{"��", "��������"},
	{"��", "˳̸ͨ���������������"},
	{"��", "Ƭ����Ϸ�����ʵ��κͻ���Ʊ��ǻ"},
	{"��", "������"},
	{"��", "������ֵ��ǿ�˹����ǰ�α�����������ε��ȶȷ��ߺ���Ƶ��ȺȻ����ʱ������ԱԽ��֧"},
	{"��", "д���׼�¼�ձ�����Ϯ"},
	{"��", "Ʊ"},
	{"��", "Ϧ�������������ǰ�հ���ʥ¶͢��ϼ��������Ұ������������"},
	{"��", "����ʪˮ"},
	{"��", "��ЦŪ"},
	{"��", "���ش�����������ϫ"},
	{"��", "��Ѩ"},
	{"��", "�ɷ�"},
	{"��", "����������"},
	{"��", "�˵��������¥������"},
	{"��", "��Ʊ��վ�Ƴ̴��������ѳ��������Ǵ������������Ƶװѵ涥��򹤻��ܼݿ�����������ģ��ƤǮǰ������̥����������"},
	{"��", "����������������Ƥƽ����̸ס"},
	{"��", "�������ؾ���ȥ���߱�����������ְ����"},
	{"��", "��"},
	{"��", "�ײ��ҹ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "���⹸����ɳ��������Ե"},
	{"��", "����౨�ٹ�������"},
	{"��", "Ĭ����˼������ԩ�������Ž�������û����˯ʹ����������"},
	{"��", "�׾�Ƥ������ɸ��������������ʤ����˵������"},
	{"��", "�ȱ��������"},
	{"��", "����������ӳ"},
	{"��", "�ִ�����ɡ��ס"},
	{"��", "�������޺ŰԱ㳼����������������Ϊνл��������Ըְ����"},
	{"��", "�������������⽨��¥ǽ���ص�����عܹ���ͷԫ���ӱ�����"},
	{"��", "Ƥɫ֭"},
	{"��", "�������ұ�����������Ⱥ�������������ݲŰܱ��ĳ��ʹ�ѶԷ��ַ�𸣹�������������ƬƷǧ����ȫ����ɫ��˫��Ϊ����Ч����ҩ������Ա����"},
	{"��", "���ݸ���¶����ʾ����������"},
	{"��", "��֮Σ�������������������������߿Ϳ�������϶"},
	{"��", "��Ա�ȿ�ʽ��"},
	{"��", "�촦������"},
	{"��", "��������"},
	{"��", "�ľ���Ƹ��Ȼ����ʵ��"},
	{"��", "����ʵ"},
	{"��", "�̳Ͽ�����ֿ"},
	{"��", "�����������ýӰ쵱�¶Ҷ��̽���������ŵƽϮ��ӡ������ת"},
	{"��", "��ǿ����"},
	{"��", "����"},
	{"��", "��ͷ��ع�իҩ���ݲ�׵����Ƚ������������Ǯ����ˮ͸��������"},
	{"��", "�ĳմ��������"},
	{"��", "���мҵ��ɺ��ƽǹ��еի��"},
	{"��", "����ˮ����"},
	{"��", "����ۻ�ĺ�����ɳ���"},
	{"��", "��"},
	{"��", "����Ԯ"},
	{"��", "��Ц��"},
	{"��", "�״��������״"},
	{"��", "��̸"},
	{"��", "��������"},
	{"��", "����ڲ������ϵ�����ڻ���ƶ������������"},
	{"��", "��"},
	{"��", "����������"},
	{"��", "����ʢ"},
	{"��", "����ֵ��⵱������������ʵ��ˮ��Ѫ��ԣ����"},
	{"��", "ͻ��ӡϴ���̵�����������ٿ�������ɱˢ��ѹײ��"},
	{"��", "�ݶ�������������"},
	{"��", "�ݵ¸߰��⾴��������������"},
	{"��", "������������"},
	{"��", "ˮ����������������������ǩȡȥɰ˰����ͷ��������ҭ��"},
	{"��", "��л���������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "���ٽ����ݿ�˼����"},
	{"��", "�챸���뵽�����������ıļ����������"},
	{"��", "�к޼���ɱ��϶Թ"},
	{"��", "����"},
	{"��", "����"},
	{"��", "�˹ֶ񻯽Ǿ���ª̬��"},
	{"��", "����Ǯζ����������"},
	{"��", "������ѧ������沽�����εȶ����ø���鼶���׾���¶��������ʼ������̽����С��ѡѮһս��ֵ����"},
	{"��", "����ڹ���ϯ����ʦ�泧���������������������ȥǮ�������Ϣ��������ɫ�����ٳ󴦵��ø۸񹤹캣��������Ҽ۽ֽ�辳�־�������·������û��������Ʒ��ȱ����ɽ��ʹʾ������ˮ̨����ͥͷ������λ��Ѫ��������Ժս��������������"},
	{"��", "ʦ"},
	{"��", "����"},
	{"��", "�������"},
	{"��", "��������ͷ"},
	{"��", "�˾�����"},
	{"��", "����"},
	{"��", "���ݷ��ǳ�ʪ��������ٺ������׳�������ȥȨȴ˪��Ϧа����"},
	{"��", "���ǹ�����"},
	{"��", "��滧���ؽ���ˮ"},
	{"��", "��"},
	{"��", "�綯�����л������Ǿ�������Ŀŭɱ������"},
	{"��", "�������������������ּ���Ůʿ������������֮����"},
	{"��", "���Ħ��"},
	{"��", "���˾��"},
	{"��", "Ь�Ĳ�̴����ÿ�ǽ�붴������͸������Խ��"},
	{"��", "��"},
	{"��", "��ͳ������Ⱦ������������鲥�����г����������ݵ綯�л��ؼǼͼҽ̾���������ýƱ����������������������˵����������Ѷ��������������"},
	{"��", "��Ʊ�˲ճ����ͼ�ͷ�׶ӷ�蹤���岰���������������岺Φβλ������Աֻ��"},
	{"��", "��Ϣ"},
	{"��", "���ɿ�������ͨ"},
	{"��", "����"},
	{"��", "����컧����ɴ̨�������"},
	{"��", "��"},
	{"��", "�ϱߵ��ڵ����ͷλϷ�����"},
	{"��", "���ع�����������"},
	{"��", "ҵ������������������ʼά���ٿ�����ۻ��������ʹ����"},
	{"��", "��ţ���������򵹵Ѷ���ҷ��ܽ�����ȥˮϮ��������"},
	{"��", "������"},
	{"��", "�ض���"},
	{"��", "����"},
	{"��", "������������ĺ��������Σ������ѯ��ֱע"},
	{"��", "�ķ�����ҩ�⻨���ٽ��첥���͸�����⺮�����Ծ�������������������ɫ������ѴѶ��װ"},
	{"��", "��"},
	{"��", "�������"},
	{"��", "��겿����"},
	{"��", "����"},
	{"��", "��������������鰮����Ȼ������ë����ƽ��Ȼɫ������"},
	{"��", "���Ĳ�����"},
	{"��", "������"},
	{"��", "�������Լ"},
	{"��", "��Ʒ���"},
	{"��", "����Ƭ��ʯ���������컯���������ͷ����ש"},
	{"��", "����������"},
	{"��", "�й�ְ��"},
	{"��", "������"},
	{"��", "������ʵ丳�ٺ�����ȥɫ��������������"},
	{"��", "�⺽���ü�ĸ��Ϫ��������"},
	{"��", "Ƭƿ��ש"},
	{"��", "�����������Ŀ��Ƶ�����������������ѡ��������׺"},
	{"��", "ʱ�°����εؿ��º󼴼����ǰ��������"},
	{"��", "����ʹ�����봩�����ǻ���Ŀ����ɱʷ̽�"},
	{"��", "��������������"},
	{"��", "����ҪƷ���ȵڷ���������Ů����֮��"},
	{"��", "������ӱ"},
	{"��", "����������ͷ����"},
	{"��", "�Ҵ�æ"},
	{"��", "���ڿ�ʼСͷҵ����δ��ǰ���ж�������������������������ĸ������ʦ��������������"},
	{"��", "�ۿ�������"},
	{"��", "�ɳ��Ͻ���������"},
	{"��", "����׳�����񻰴�ϸ�Ź��ɲ�Ұ�ں��ӿ�����ª³����ǳ��������"},
	{"��", "��������"},
	{"��", "��ӵ"},
	{"��", "�ɽ���ʹϥ��"},
	{"��", "��Խ��"},
	{"��", "���Ȩλ"},
	{"��", "������"},
	{"��", "�л�����"},
	{"��", "Ρ�"},
	{"��", "�߿��ƻ������ٸ���"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��ɫ�����������΢"},
	{"��", "�쳤��ׯ����򸾹���������կ��"},
	{"��", "��Ǯȡ��鴢�����Ÿ��������������ˮ��������������֤��ߡ"},
	{"��", "�����������"},
	{"��", "��̸"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��ʧ����©��"},
	{"��", "ʩ��"},
	{"��", "��"},
	{"��", "���𴦹ֹ�"},
	{"��", "��"},
	{"��", "λ�ֻ�����"},
	{"��", "����"},
	{"��", "����"},
	{"��", "�������"},
	{"��", "�˵��û��������������ǻ������ڨ"},
	{"��", "���ɹٹۼ���������Ħ��ʿ����"},
	{"��", "л�����ʸ�����Ӧ����ʴ���Ծ�����ǻ��"},
	{"��", "��ӡ�ּ��ƿ����Ż�������ͨ���ƽ�����ܰ�����в��Ĳ����ɳ������������Ϸ������ֹĹ��û�ٽٽ���������������������ƴǹ��Ȥȭ��ɨ��������̥̽��ͷ������ѹ������������������סת׮������"},
	{"��", "��רѧ�ط������������������ں����ູ�����ͰӰװܰ�챯�ʱ������س����������˳�ȴ󵶵̵еֵ����ǶӶෲ��������Ÿɸٸ�繦���ع۹������úźӺ�������������ƽ������нֽݽ��־پ����޿�����������¥·½��������æĮ������������Ƭ����ǧ������Ȩȫ����ɩɽ��������ʤʥʦʹʿ����������ˮ����������ͬͷ������ΪϪϲϺ������СУЦд������ѡѩ��������үұҵ������ӹ��������԰ԺԼ��չս����ץ��������"},
	{"��", "�������������"},
	{"��", "ͽ��"},
	{"��", "��"},
	{"��", "����Т��"},
	{"��", "�߻�������·ȥ�������Ӹ�������������ͷ������������״����"},
	{"��", "������������ʲ��ʴ����������ܺżۿ�������Ϊл������"},
	{"��", "���������"},
	{"��", "��װ��"},
	{"��", "ҵ����������������"},
	{"��", "������ס"},
	{"��", "����ʻ"},
	{"��", "������"},
	{"��", "�����γд������ٸ�ܾ�ˮ����"},
	{"��", "���׶�������������ϼ����"},
	{"��", "λһ�м۴��ִ򴿱���������̴������������ڸɸܸ����������ݿ���������ɫ������������Ԫ������"},
	{"��", "��"},
	{"��", "Сʶ��Һ�����������ɫ֭��"},
	{"��", "����Ϧ"},
	{"��", "������"},
	{"��", "Ը���Է�����Ҫ����"},
	{"��", "�����������󵭺컯����ĮȻ��ˮ��ױ"},
	{"��", "����"},
	{"��", "�ٳ��������ۻɻؿǿ�Ƭ����ͷ������ѹҩָ��������"},
	{"��", "��ư׿���Ʒ��"},
	{"��", "����ǰ��������������ͷ��ʱ��Ȼ�ٹ�־ְ������ɳ����������غû�����Ʊ��Ȩ������������ѡҹ����ֵ������"},
	{"��", "����·��ס"},
	{"��", "ί�����ı��ηѷ�ٹ����ͽ����ο�������Ʊ��Ⱥ��ʷ������У����Ա����"},
	{"��", "��������Ȼ��"},
	{"��", "������"},
	{"��", "Ƭ�̱��ʱ����۽��߿���ǹ����е����"},
	{"��", "�ҵ�������"},
	{"��", "��Ϯ��"},
	{"��", "��ù�ѱбղʳ������ط���ҹ໻������������̨̮����ͷ��������үӰ������ת�"},
	{"��", "�ǹ�������"},
	{"��", "�ʸ�"},
	{"��", "��������������ܺ�������������������ʦ��������"},
	{"��", "ʱ�״���ͷλ�밸�����㶥�û��������������"},
	{"��", "�ݳǹ���������������"},
	{"��", "������"},
	{"��", "�ױ����Ǹ��ѧ���ѹ۹�ؼҽ̾���·����л������ǫ����ʿͳϲ"},
	{"��", "�淥�˺�������Ĺ��ȡӡ����"},
	{"��", "�ųǹ��ݾ�����������������ԣ��������"},
	{"��", "�⵽���������ѳ�ȳ��������ֱ��ܾ���������Ʊʤʧʱ��������Ϥ������֪־��"},
	{"��", "��ȷʿ�绰��"},
	{"��", "�����ݻ�ͷо��յ�ֲݶ�ܹ��ܽھ߿�����˿������"},
	{"��", "��ɽ�ű���¼½��������̨�������������¥��ʱ������"},
	{"��", "�ڼ�������ȵصڱȲ�ηָߺż۽Ǿ�����������ͬ����Ч��ֵ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��ɿ���"},
	{"��", "���ӷ�"},
	{"��", "�����׵��ȼ�������ͷ������΢�������������ضȶ˷ɷֹ��ȺĻؼ���������ü����Ƶ��ʪ��Ϣ����Чн��ѹ������"},
	{"��", "�����ˮ��Ѫ"},
	{"��", "��"},
	{"��", "���˶Է������������ǰ����α������"},
	{"��", "Ĥ����"},
	{"��", "��"},
	{"��", "����ϵ��"},
	{"��", "���������Ƴ䴥�����������Ѻ��ծ��ס��"},
	{"��", "���߲��㶨���������Ƭɫ��ϸ������н������"},
	{"��", "��ַ��������������ͷͼλ����̯̺�層������������Ŵ�����綴�ι����ϻ����۽ѽ�ǿ�������©��òĤ��ƤƦ������Ȩ��������˰ί��������ѧѹ��������֧��"},
	{"��", "һ�����˾�����ʮ����"},
	{"��", "��������˴��λҢ��"},
	{"��", "����ϱ����"},
	{"��", "�䲹�ʸ���Ӽ����������������"},
	{"��", "������Լ��"},
	{"��", "���帲��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "������֪������ͷ��貥�˳����ư��ε㻯��콫����������������ȼȾ����������ѡѨ����������׺����"},
	{"��", "�Ͳص����ʼ�������������"},
	{"��", "�屳�׸����Ȧ����"},
	{"��", "���Ի�������Ӱ�ص�"},
	{"��", "��"},
	{"��", "������̨��������Դ�����������ʴŲ��󳵴����װ��Ƹ湤�⺯�ɱ��ػ�����������̽�����������¯·����ťƿ����������Ͳ����λ����ѧѶѹ����բվ����"},
	{"��", "��ũ��"},
	{"��", "��������������Ա"},
	{"��", "����"},
	{"��", "��������"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "��"},
	{"��", "�ɻ������������������"},
	{"��", "����ήл"},
	{"��", "�ѻ�������"},
	{"��", "��ͷ�ӻ�������ɫ����ת"},
	{"��", "�����ƹ���������Ͱ����װ"},
	{"��", "�����;���"},
	{"��", "����ζ���ְ�����������������̽�������Ƥ���ͺϳ������Ͷȷ��߲���������������ƵǨǲ����ɫ����ͣͷϢϷЭгн������������������٩"},
	{"��", "���۽�������������ͣ�����"},
	{"��", "�ص�����"},
	{"��", "Ƭ��"},
	{"��", "��ʽ��Ӿ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�����ݼ���"},
	{"��", "����������ϩ����"},
	{"��", "��ס"},
	{"��", "��ҧ������"},
	{"��", "Ьס�Ӱ�������"},
	{"��", "��������ͷ����סײ�˶����Ǻü������¥��������������"},
	{"��", "�������к�����ʢ��"},
	{"��", "����"},
	{"��", "��λ����������ֻ�����ư���������㶼�����溣���۽𾦾�������������������Ȼ��ʱʹʽ����Ϊ����������ҵ��Ӱ����ԱԼ��סװ��"},
	{"��", "����λ���𶨷���������Ϊ���ɳ�����Լ������������"},
	{"��", "ʧ������������"},
	{"��", "�ϱ���ݸ��ɽ���ϲ������߲ന�����ɷ��Ƿ繬�����ҽ�����������·����ŷ��ƽ����ʩ��������������վ֥���"},
	{"��", "���Ĳ˲ط����ϼ�����������ѵ��Ӿ��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "����"},
	{"��", "�ﻭ����������������ҡ�ʲ��ʴֵ����л�����������ŭ��������̬����������Ա����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������������"},
	{"��", "�ڲ췿������ͥϤѨ��"},
	{"��", "������������"},
	{"��", "��������"},
	{"��", "־�Ǵ󵨷�����Ź������ʿ��������"},
	{"��", "�ھ�����Ȼ"},
	{"��", "�긯���Խ��ǿ���������ɳѿ������ޢ��"},
	{"��", "������ŪȤЦ��"},
	{"��", "����Ҫ�гǶ��Ժû�������"},
	{"��", "���ٵ�����������ѧ����ս"},
	{"��", "Ʒ�Բݳ�򸾺��߻�������������ɱ����������ҩҺ֭����"},
	{"��", "����ռ�����аԳ��ײ��ô������öϾӾ�������ȱ����������������"},
	{"��", "��ȡ��д���������ϳ�������������ʫ��ͼ����"},
	{"��", "����ס��"},
	{"��", "��˼��"},
	{"��", "�����������־߿�����Ǯͽ��ծ����ע"},
	{"��", "���������׫"},
	{"��", "����п��"},
	{"��", "������Ƥ������"},
	{"��", "����������"},
	{"��", "�۴������Ӽٽ�����ͷ"},
	{"��", "�����ռ�����"},
	{"��", "��ׯ�ڲ˳�������������������"},
	{"��", "��ƪ����Ѷ����װȹ�����̴��ٴ򵶵Ѷ̷�������ž���·��������ǳȱ��ʫ��ʹ;������С�"},
	{"��", "����ѹ��"},
	{"��", "��ʽ��"},
	{"��", "��Ȼ�㳦�̰���������綨�������俪������·������Ƭ������ˮ��ͷ����������������֫"},
	{"��", "����"},
	{"��", "�ɷŷʺ�����ջ"},
	{"��", "����������"},
	{"��", "�鲿��������������ҽ��Ա"},
	{"��", "��ס��֢���𽲷�����Ӧ�����ֽ�֤��ż���氶�װ뱾�ȱʱ߲߳��Ƴ�˴�����ȵе����ָ������Ż������ҽ��ǽӽ󾢾־���������������·����̸ͷϺӳ����������������׼�����"},
	{"��", "λ"},
	{"��", "��"},
	{"��", "�ٺ����Ƹ����ʵ"},
	{"��", "�ɴ�кŽ��Ž�Ȼʱ������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�شʼ�����������"},
	{"��", "ʰ"},
	{"��", "��"},
	{"��", "����������лô��Ԫ���ΰ�߱�ʲ������õ�˶෽�ָ���ѹ��ú˼����Ҽ��ÿ׿�������������ʱ��ͷΪ����������������������֭��"},
	{"��", "ȡȥȨ��ùڻؿ���Ŀ"},
	{"��", "�ܿ������ڲ�ծ"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����̥"},
	{"��", "ü"},
	{"��", "�ڲ���ü��"},
	{"��", "����ë��"},
	{"��", "�۶���������ʽ����"},
	{"��", "���Ƚ���ͷ��"},
	{"��", "����թ"},
	{"��", "ü"},
	{"��", "�������ζ��Ա��������й��������Ļ���������ħȮ������ͽϰ������ҵ������ս�����"},
	{"��", "�϶����"},
	{"��", "ɱ������Ҫס��"},
	{"��", "��ֹ����"},
	{"��", "�״�����"},
	{"��", "������"},
	{"��", "������������ƽ����ʦԹ�͵���"},
	{"��", "�Ҷ��������������"},
	{"��", "ͯ���Ů��ϱϷ��"},
	{"��", "������߲����������������Ŀ������˳����"},
	{"��", "�Ⱥ���ʱ��"},
	{"��", "���Ȱٴ�¥����ǧ��Ԫ�����ƻɻ���ʮά������"},
	{"��", "�������ﲼչ�����Ӵ���ձ����Էߵ��ж��ŷ�������Ʊ�;���֤�����������й��ѿ�����Ƴ��ⲡ���踣ù�������Żؼ��ʼмҽ;���Ȱ�������ŭ��������ɢ������������ЦԴ�����"},
	{"��", "��Ǯ��������վ��"},
	{"��", "ľ"},
	{"��", "��ζָ"},
	{"��", "��"},
	{"��", "��ͥ�ƹ�Ժ�ٹ�����ʦ����������ȷ����żͼҾ����������챦������ä������Ȩ��ʩʽ��������ͳ������ϵ��ѧ��ҽ����ӡ������ִּ�������"},
	{"��", "����"},
	{"��", "����"},
	{"��", "خ�ع�����������"},
	{"��", "���������汾�����������������ɸǹ���������Ū����������ӡԽ��ת��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "������ֳ����ʢæï�ิ����������ϸ����������"},
	{"��", "�³�����������ʥ������"},
	{"��", "��������������������������"},
	{"��", "��ӦĿӳ��֤�渴�⶯���������ж����ڻ�θ���俹�����Ȳ�����Ĵ����۷����ۻ����������������ʡ��˼����ս֮תۻ"},
	{"��", "�������س��̵ֹ�������У����"},
	{"��", "Χ����ʽ����"},
	{"��", "����˽����"},
	{"��", "�������������ɼͽ������������"},
	{"��", "�˵�ݺк������Ʊǰʳ����Ͱ��ׯ��"},
	{"��", "�Ʒ���������ָ��"},
	{"��", "��"},
	{"��", "�ݴ�ƻ�������������Է"},
	{"��", "�������������λ��ʽ�����ų̳ߴ�������ɿ���������ʼʿͷ������Բ������־������"},
	{"��", "��������ݼۼ䶫���������ӸĶ����ǿ�����"},
	{"��", "����縯�����߲���������ʪˮ����ֹ���Ƴ������ط��������������Ѵ��������"},
	{"��", "����"},
	{"��", "�����Ч��������"},
	{"��", "�ʲ��ſ���������������̸��"},
	{"��", "֯����ɴ˿"},
	{"��", "��ӳ���¿�������������ƨ������ѧ�߹������ţ�������綾���ؼٽ��տ�����������������������������ˮ����Ѫ��������������"},
	{"��", "����ͬ�޷�"},
	{"��", "��"},
	{"��", "������������Ҳ�䷲������"},
	{"��", "��������������ȥ������������ʯ���ǹ��۳浯������Ƚ�����ĭ������ɢ����������ӥ��ԽԾ������"},
	{"��", "��������׳����������������ȱˮ��Ч"},
	{"��", "�����ͽ"},
	{"��", "��"},
	{"��", "����"},
	{"��", "���������೦��������"},
	{"��", "Ʒ�����˻��ڳ�����������Ʊ����ʱˮ��Һ����ֹֽ����"},
	{"��", "ˮ�����"},
	{"��", "�������óǵ繤���⾢Ǯ��ʱ��"},
	{"��", "����"},
	{"��", "ȩ��֬"},
	{"��", "��"},
	{"��", "Χ"},
	{"��", "���������뼶������鹤����������ͷ����������Ӿֿ�����Ҹ�źϵ�ζӱ���������㳡Ժ�ɳ��絵�ѵ÷����������ܺ���컯����������������ĸ������Ǯ��ɢ������ʱ����˵��̯����Ϊ������У����Ұҳ��֧֮��"},
	{"��", "���ʷ��ɷ��������������"},
	{"��", "��Ĺͷ��"},
	{"��", "����������"},
	{"��", "��ˮ��"},
	{"��", "��˿���ױʱ����ʳ��̵׵������ĩĭƤ��ǽɫɰ��ˢ��״"},
	{"��", "�����½�����ս"},
	{"��", "��������"},
	{"��", "�޺�Ȼ"},
	{"��", "ŭ�ߺ޼�����Ȼ����"},
	{"��", "��ʿ�����"},
	{"��", "���չ�����ԣ���ɲ��Ƕ�������������ʢʵ˳˶̨����ӯ������������"},
	{"��", "��ɽ����������Ƥ��׶����źɱ����Ϊӡסװ��"},
	{"��", "����Ҷ"},
	{"��", "ӵ��������Ⱥ����"},
	{"��", "������"},
	{"��", "��â��"},
	{"��", "�����ɳ�������������������������ʪ�������ȶȺ���������ζ��Ȥɧɳˮͷ�����Ʒ��ǹ⻯��Ϳ�����������ò��������˪������������������"},
	{"��", "�ߵ߹���̱���"},
	{"��", "��"},
	{"��", "����Ϸӭ"},
	{"��", "����"},
	{"��", "���ú�����϶��"},
	{"��", "����"},
	{"��", "���׹�Ȱ�и滹��������������ּ��"},
	{"��", "�ǹڻ�ɽ����"},
	{"��", "�̾����䷨�Թ���ż�����ɽ������˵������������Э����ѧӡ����"},
	{"��", "��������"},
	{"��", "���Ҿ���Ȩ������"},
	{"��", "��������ҩ"},
	{"��", "Ƥ�ʲ�ǳɫ"},
	{"��", "����������"},
	{"��", "����������ƶ��ɣ����Σҡ����ֲ��"},
	{"��", "������������"},
	{"��", "��"},
	{"��", "����Ա"},
	{"��", "�źϽ���"},
	{"��", "�����ʵط���������������"},
	{"��", "��²"},
	{"��", "���װ��ҩ�۶�����ɥʳ����������������"},
	{"��", "����������Ƴ�������񷺻���������Ƽ��ǳ����ͼ��������"},
	{"��", "��"},
	{"��", "��������������Ƕ��ֽ���������Ȫ��ҵ������"},
	{"��", "������"},
	{"��", "ʿ"},
	{"��", "������Ūƽ��˳ο������"},
	{"��", "��������������"},
	{"��", "�����ʰ���������"},
	{"��", "�׳�нɽ"},
	{"��", "��ͷ����"},
	{"��", "�û����������"},
	{"��", "��������"},
	{"��", "����ʴ"},
	{"��", "�ῼ����Լ"},
	{"��", "��ʳ���ٱ��ʽ���������ҵ��ְ��"},
	{"��", "�Ǻ�û��������"},
	{"��", "��ʫ˰����������ֵ"},
	{"��", "��ӡ��ϰ��д�ֺ�����ְ��λ����ҵ������緢�����Ź����˻��ɿ�����Ȩ������������������ѧ��ԪԭԱ"},
	{"��", "������Ѹ���Ǯ����ӡ����������������"},
	{"��", "��ɳ����"},
	{"��", "ĸ�ױ�������ŮȨ��ϵ����ִ"},
	{"��", "ʹк���ظ���ǻ����"},
	{"��", "��ծ����źɼ���Ƭ��������������Լ������"},
	{"��", "������ʿ�ڹ����������̺����ҽ㿵����ũǿ������ԣԴ��"},
	{"��", "������"},
	{"��", "���Ӽ�����������Լ����¼����������ͼС����ӹ������ע��"},
	{"��", "����Ů�׵���¿�����"},
	{"��", "��֮��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "��������������������װд�����۴��ɳƵ��������ڼ޽���������Ϊ��С����ѡ����������"},
	{"��", "�������ƹ���������ò��˵��̾Ҫ��"},
	{"��", "����"},
	{"��", "��ӡ�°�Ķ�������ס��"},
	{"��", "������ྻ�����������������˲ݷ��۸�����Ի���;��ʿ�����������Ⱥʬ��ϵ��У��Ԥ֧"},
	{"��", "���Ĳ�����𵱿���¶ð����Ȫ������Ը"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "���װ������༲"},
	{"��", "��·�߳����ؽ�������æ����ȥ�ϸ���������"},
	{"��", "���鼤л����Ⱦ�˵�����ð����������Ӧ̾��������廯����֪�"},
	{"��", "������˵�ɽ���Ϊ��������"},
	{"��", "����"},
	{"��", "ɽ"},
	{"��", "��ֱ㹲Ÿ���Ҫ�ý���ǿ�ɹ�����"},
	{"��", "������˿��ʲĳ������ǹܹ������ƤƬƿɰˮ������"},
	{"��", "��"},
	{"��", "����"},
	{"��", "�쳣��ĿҪ"},
	{"��", "λǰ��ͤ"},
	{"��", "��̨��Ԫ�ڱ����嶽�����ſ�����"},
	{"��", "����"},
	{"��", "���¶ȸ���¥ɽѹ�������ٵ�Ч�ַ��в����У�˵ȵ͵ص����ſ�����"},
	{"��", "ҩ"},
	{"��", "ǿ��������Ҫ�������������������̳�����˶�ɹ��ٺ������;Ӿٿ�������������¯����������ƱƵƽǽɮ����������̨Σλ��Сн����ҽ����ԭԶ����ְ��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "������Ц�ҵ��µõඨ�ɹ���������Ǯͨ��"},
	{"��", "ͷ"},
	{"��", "��Ѽ�ԴԼֽ��"},
	{"��", "������֪״�ܴǴ����׼��ɴ��ٽݽ���ʾ����οл��"},
	{"��", "�������"},
	{"��", "�質��������������̳��Ů�׺������̶�����ҥӽ"},
	{"��", "ǳ����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�۲�"},
	{"��", "��"},
	{"��", "�����ݳ��ضϾ�������"},
	{"��", "����ְ����"},
	{"��", "��"},
	{"��", "��ʽ�ָ�ɱ���������λ������"},
	{"��", "���"},
	{"��", "¥��Ա"},
	{"��", "��Ĥ��ڿ�����źҼ����������ɽ������ҹ����"},
	{"��", "�����λ�����������ͷ������"},
	{"��", "������ʽʡ�������ط��ؽ������˽���𴦴��λ����ҵ������ɫ���������ˮ����������������"},
	{"��", "���ݲ����׵�źӻ�������ë��ʽϵ����Դ������"},
	{"��", "�����ǰ������ͷׯ����"},
	{"��", "�ض���ţũ����������ݷ"},
	{"��", "�üӶ����¿����Ϊ�Ǵ������������»���������ǿ������СҪ����"},
	{"��", "��"},
	{"��", "����ֱ"},
	{"��", "����ֱ��"},
	{"��", "��������ҵ�������ũ���᳡������ó������ʱ�ʱ������η����ַ�����ƿ���Ǯ��ͷίЧн������ְ��װ"},
	{"��", "����"},
	{"��", "�䲻���ع�"},
	{"��", "���ܷ�Ч����"},
	{"��", "�ƳǴ�"},
	{"��", "��"},
	{"��", "ȡ��"},
	{"��", "��"},
	{"��", "����Է���������"},
	{"��", "ҵ��"},
	{"��", "����ռ"},
	{"��", "�׷��Ź��ļ�����ѫ"},
	{"��", "ϲ�����غ����˳ף��άӭ��"},
	{"��", "����"},
	{"��", "������Ӧ��ˮ���Ƴ���Ʒ����ů����������ְס��"},
	{"��", "��"},
	{"��", "��˾����ƽ˽��·��֤�����������ｻ����ʽ������Ԫ԰�²ް챨����ϳߵ����µеض϶ַ����ѷַ߸ɸ湫�ݺ������ἦ�Ҿ��˿�������������ĶĹľ������������Ȼ������ʹʾ��������Ͷ����������ӪԢԼ��ծְ������"},
	{"��", "���Ƶ���Ů��ͥ͢������"},
	{"��", "����"},
	{"��", "������"},
	{"��", "��"},
	{"��", "������������"},
	{"��", "��Ʒ��Ժ"},
	{"��", "�����������д������öȸ��ܼƽ����۾�������ʶ��ͨ����ҵ��"},
	{"��", "��"},
	{"��", "�����һ���ס������������ȡͨ��"},
	{"��", "Ů��ͨ����"},
	{"��", "���ϻ���ͬ"},
	{"��", "��ƨ����ʳʺͷ�ܱ��ŷ�"},
	{"��", "�ɼ���˼ͼ��������"},
	{"��", "�����������������ò���"},
	{"��", "��������ζǺ������"},
	{"��", "��"},
	{"��", "���"},
	{"��", "�Ʋ����������"},
	{"��", "������"},
	{"��", "�������Ѿ�����Ƨ��������ŵ���ªŮ���"},
	{"��", "Ϣ����ү�ɹ�ɩĸ����򸸾�������"},
	{"��", "��������������ƴ�����������¥Ĥ�����"},
	{"��", "���͵����������ϡ����ʫʱ��層���Ǵ����������󼣾�����Ĺ��Ǯ��ɲ������ѵ����Գ��װ��"},
	{"��", "����"},
	{"��", "��ͷ�ܽڿư��̶���ɻ���µĤ��������Ѫ������"},
	{"��", "����׵�����"},
	{"��", "Ʊ���б������ֹǼ۽�����ȨϢԱ"},
	{"��", "���¹����ϳǴ˵���̬�����������ɾ�������ʵ������԰ֽ֪"},
	{"��", "������ȫ��ϧ�ǵ����ɼҿ���ίԱ��"},
	{"��", "��ԭִ��ʼ�д�����Ȼ��̬"},
	{"��", "Ӷ����ũ����Ա��"},
	{"��", "��ϴθ���˵���������"},
	{"��", "��������Ƥ����"},
	{"��", "�����ڸ���Ů����ͷ��"},
	{"��", "��������ǣʧ˧�ʵ�����������������ְ"},
	{"��", "��"},
	{"��", "��Ƨ�������"},
	{"��", "��������ƭ������"},
	{"��", "�������������˲��е�������ƧȦʯ����̸̥��Թ���"},
	{"��", "��ľ"},
	{"��", "ϵ���ż��������ձջ�����עͷ���п��ڰ������Ƶ�����������������ɽ��˰��Ѻ����ջ�����"},
	{"��", "�������λӡԱ�˰쵹���������¼Ҽ۽׾�������������ǻ����ʷ����˾������Уְ��ۡ�"},
	{"��", "�������Դ���"},
	{"��", "�������������㿴�й⺣Ħ��հֹ"},
	{"��", "���Ҽ������������ڵ��ܺ��ӿ���·Ͻ����������״"},
	{"��", "�س���ǰ��Ա��"},
	{"��", "ͷװ��"},
	{"��", "���ó�������"},
	{"��", "�����ȸ彬ľ����ˮע��"},
	{"��", "��������ͨע"},
	{"��", "�ٻ����ڲʺϵ���˽����ٵ�������ͷ����ȸ��˹���������ŰͰ߱ʲ�������â������Ȧ������������ѧ��ҫӰԴ��դ����"},
	{"��", "�ݸ涫���󲥽����巺����������ȸ̰�Į��ˮΪ��ҽԪ��"},
	{"��", "����"},
	{"��", "����"},
	{"��", "������ģ�������Ȱ������Լ�ܳ�"},
	{"��", "����"},
	{"��", "�ֹ���"},
	{"��", "���������������������ڻ����̵����Ӹ������������̿�����������������˳����;λ����������Ԫ��������"},
	{"��", "�׿���ɽ��ͷ"},
	{"��", "����Ů��Թ"},
	{"��", "������"},
	{"��", "�������ֻ����������ڲų�����̥����������"},
	{"��", "���������թ��"},
	{"��", "�ֻ�Ƥƽ�����Բ��"},
	{"��", "̨��"},
	{"��", "����"},
	{"��", "��˾�����������տͱ����ط����۹�����ʡ��Ժ����"},
	{"��", "����"},
	{"��", "�鶯�ߵ��ع�����������������ˮ��ͲԲ��"},
	{"��", "����"},
	{"��", "�͸�¯̨��"},
	{"��", "ĭ���"},
	{"��", "��ר���Ҽ�����Ӫ����ɫ̩˰�ⱦ���߲��ܴ󶼶ȷ��������⻨���ջ�������Ž̽羳��������������������������ʦʷ����������������������ѧ��ҩҽ������լծ"},
	{"��", "Ȼ֭����԰�����˵�ƤƷ���ⶳ�ϸ����Һ˽����ƾ���ľũ��ʵ��λӬ"},
	{"��", "������вס��"},
	{"��", "��������ʧȥĿ���˷ָ߹ضɵð뻧��������̴���ͷ����ҹ����������ʱ����·�Ȱ����ӵ������Ͷ��̶�ߺ��𼤼̽�����������ʢʣ����ˮϸӲ����"},
	{"��", "�͹�����������Ƿ������ά���"},
	{"��", "��"},
	{"��", "ͯ�Ӷ���"},
	{"��", "��ھ�ˮ�������Ϲصױ��ΰ���Ͽ½�ʴ�����ζ��ϼ�徰�������߲����˲����ε����̵ض˷����۹���꺭�ӽ�����������·������������������Ÿ��ɽ����ʴ��̲��ͨ��Х������ӡ����Ա��սר��"},
	{"��", "���߲��洦������ϲ��"},
	{"��", "��Ȼ��"},
	{"��", "��˯ս��"},
	{"��", "��ֱ̬"},
	{"��", "��"},
	{"��", "������ս"},
	{"��", "������Цˮ���ߺ޻���������ŭ��ԩ��"},
	{"��", "���ǹ���������"},
	{"��", "����ٷ��䴰�����������ս������¶÷��ɽ˪΢��������������"},
	{"��", "�ڵ繺����������"},
	{"��", "ԩ������������ס"},
	{"��", "������"},
	{"��", "����ī"},
	{"��", "��"},
	{"��", "����"},
	{"��", "����"},
	{"��", "���ؼ�����"},
	{"��", "����"},
	{"��", "����Ȼ"},
	{"��", "����ǹ��"},
	{"��", "������ë��ˮζ������"},
	{"��", "���ﱤ�峯�Ǵ��������齭��������������ˮ������ѧ��ҽ����Ӣ����"},
	{"��", "��"},
	{"��", "���캣�������������̴��ε���·ģĸ��Ȩҵ����"},
	{"��", "��"},
	{"��", "����"},
	{"��", "�黪լ����ˬ���ٿͶĶ��������ǿ����������׳"},
	{"��", "������������ë��"},
	{"��", "�˵���ѧ���³���ɫ��಻�⺺���漸����תϷ����ЦЩ�ܾÿ����߲ʴ��������û������Ͱ�ȵ϶�������ǿ����ʤʹ����˵��������ս��"},
	{"��", "�ĵ���ѽ߾�����ȥʱ��������"},
	{"��", "���Ƶƽǽ�����������Ϊ��������"},
	{"��", "�󵴷���������Ȼ���"},
	{"��", "��ǻ�Ƿ��"},
	{"��", "ˮ�ʲ������������"},
	{"��", "��������Ҷ��"},
	{"��", "����ս�����緢�İ��Զ�������ͻ�Ƽۼ�������ʵ��������׼��"},
	{"��", "����"},
	{"��", "ƽ�Ⱚ���ú�̸���Ƴ��������������ů��������˳����ЭгѶ��Լ������"},
	{"��", "�ؿ�ʱ��಻�����ȷ����ɹ�����ν������ֹ��"},
	{"��", "����ͬ������ӪӰ���ʼҳ���Լ���������ɺû���ı�������ȼƽ�����£�챧��������Ⱥ����ʮʽ��Ϊгһ������������ס�������"},
	{"��", "��װ��"},
	{"��", "�ϱ��۰��߱����۳ش��������̵׶����Ⱥ������������������ɽˮ̲����ϵзԴ������"},
	{"��", "��֮��"},
	{"��", "�Ź����Ȼ����"},
	{"��", "ɫ"},
	{"��", "�ڸ���ɽ"},
	{"��", "�꿨�ʵ纯��������ϲ����"},
	{"��", "��"},
	{"��", "������ɫ�ƶ�ҹӰ��è�߰����񹷹����Ӻֻ�����ĻūơǦǮ����ʯ������̿��ͷ����������������"},
	{"��", "��"},
	{"��", "�ö���С���Ѵ�߻��ÿ�Ͷ̹��䳤����ǿ��������"},
	{"��", "��������ץ"},
	{"��", "����������"},
	{"��", "����"},
	{"��", "��ͨ"},
	{"��", "���������ɶϲƳ·�����ӿ�������ľ��������ɨɽ��������д��Խب"},
	{"��", "����ɽˮ��"},
	{"��", "������ɳɽ������"},
	{"��", "�䶯��¡��Ȼ��ը"},
	{"��", "ƭ����̧��Ц"},
	{"��", "���ɿ�����"},
	{"��", "����"},
	{"��", "ͼ����ë������ҵ��־"},
	{"��", "ˮ���帣������������������"},
	{"��", "ΰ�۴󸻻�������ͼҵԸּ"},
	{"��", "��������һԸ"},
	{"��", "������¥�ƹ��ջ����������ɫ�����ư߰���÷���޳��ۺ��ӻ𽷾�������ë��õ��ľŮ͸����������ѧҶ����������ש����"},
	{"��", "�������ͷ����"},
	{"��", "���־���"},
	{"��", "��Ϸ�Ӽ�"},
	{"��", "����"},
	{"��", "��������ֽ���������ʵ����������"},
	{"��", "��ѡ��������ݽ�����"},
	{"��", "����̨�챸���������˹���·���߳����ܷ������ǽ���������������������������ͷ��������Ժ��׺��"},
	{"��", "�����оȳ����ź�������Х��Ӧ����"},
	{"��", "Ȼ�ض�������������"},
	{"��", "˵�Խ�����"},
	{"��", "«"},
	{"��", "��������绰����������ͬ��������"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "��ŪͿֽ"},
	{"��", "���ϱ����������ɫˮ��������"},
	{"��", "�ȹ�����"},
	{"��", "��������������������Ƥ����ХѨ����"},
	{"��", "��ס"},
	{"��", "���ֱӳ��Ͷ̷��������ݽ̾���·��ǽ��ʿϥУ������ר"},
	{"��", "������ͨ�������������û�������Ź����������Ϊ��ѡ����ף"},
	{"��", "��"},
	{"��", "����������ͷ��������"},
	{"��", "����������԰����ƿ�ѵ��ݳ�����Ե��Ƶ񶼶��װ�߷ۻ��ܻἾ�׽����ξ�����������ľ������������Ǯǻ��Ȧɫ��ʽ̳������������Ѻ����"},
	{"��", "�仩��Ȼ"},
	{"��", "������ɽʦ˶٢�����������Ƶ�ǹ��������������ɳ��������������������"},
	{"��", "������������˹�������������������ˮ��ͷ��������ѩ"},
	{"��", "ͼ�Ҽܽ�չü��屨�ʲ���ɳ������ַ����幤������羰����������ƤƬ������ʦʷ����Ϊ��ѺҳԺֽ��"},
	{"��", "�岦�ɳ��������ֹ�翪ȭ��Ϊ��һ"},
	{"��", "ѧ����ױ���ɳ��ʺϽ⾳����ŧ��ʯ��Ϊ������Եװ����"},
	{"��", "�����Ͳ�����÷����ɾ�������˵ͷ"},
	{"��", "��"},
	{"��", "�ɱ���������̥���ɹű��Ŵ��º�����������Զ"},
	{"��", "������������"},
	{"��", "�����Ļ�������������͸��"},
	{"��", "ӭ����ϲЦ������Ⱦۿ����ճ�����������������"},
	{"��", "�������˺�����������ɽ����������״��"},
	{"��", "����Ҫ��ԭԸ����ûծ���۽����û�������Ǯ��ʦ����δ��������Ӧ��"},
	{"��", "��֮�Ʋ����ͻ������������а�����"},
	{"��", "�೵�ɳ˴����������������������ȡ��������λ��ϴЬ������ҩҳԼװ"},
	{"��", "�ѷ��޲�����������"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ɢ"},
	{"��", "��;"},
	{"��", "������ƻ�����������Ӱ"},
	{"��", "�ݵ�"},
	{"��", "������"},
	{"��", "���طϽ�������Į��Ƨ��ɽ��̲������Ұ��ԭ"},
	{"��", "��æ��"},
	{"��", "ɫ�����ҵ��ֹϹڵƵ۵�����ǳ��Ժ��ӻ�����ƾ�������÷ţ����Ȫɳɽʯ��ͭ����Ҷ��������ݺ���������"},
	{"��", "Ϫ"},
	{"��", "��"},
	{"��", "Ƭ"},
	{"��", "���۸����ں��������ͳ��λ����"},
	{"��", "�̻��"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "����"},
	{"��", "Ȼ���"},
	{"��", "���ƻ���"},
	{"��", "���׳��Ⱥڽ�����ɫɳʯ��"},
	{"��", "����۱ޱ��������������������ȭ��"},
	{"��", "����ӳ"},
	{"��", "��ī��"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��ͷζ�������´������ϼҼ����˱��ܲ��̴�����������÷Ÿ����������ػ��̾�����������¯·����������ȥ������ʦ������������������Ӧ��ִת������"},
	{"��", "������������������������Լ"},
	{"��", "�Ĺ���������"},
	{"��", "������˼��������"},
	{"��", "���涫�������������������"},
	{"��", "����ɬ"},
	{"��", "¸ѡ"},
	{"��", "����������"},
	{"��", "����̸��������ԱԼչ�ѲͲ��������ѹݺ��Ϻ󻰼����žۿ�����������ǰ������ʦ��������ͬ����������Ҫ������ս����ַ��"},
	{"��", "��"},
	{"��", "���ɳ����ҷѷ�ϼ��۽�����£��Ʊ������"},
	{"��", "ͼ"},
	{"��", "����ҽ��"},
	{"��", "�˲���"},
	{"��", "�ɳ���Ӱ��"},
	{"��", "����"},
	{"��", "��˯���������ƾ�ѣӹ��"},
	{"��", "����ɴ����ټ޼��������Լ��ǰȢ��"},
	{"��", "����������"},
	{"��", "������Ȼ��ˮԲ��ج��"},
	{"��", "��Ϊ�ҳɳ䵰���Ļ켣������ˮͬ��Ѫ����ս��������"},
	{"��", "��ȥ������Ȼ��"},
	{"��", "��������ԾѪ��û�ƿ�·����������Ȫ������ˮ������ҳ������"},
	{"��", "�鷿��ʳͬ"},
	{"��", "��ҩ�����ϼ�����������������¯������ѳ����������ѹ����򻯿�������ţ������ǹ������ɽ����ʯ����������������"},
	{"��", "�ý�����ȡ��ʤϤѡ��֪��׼��"},
	{"��", "��Ȼ������"},
	{"��", "��"},
	{"��", "�ض�����Ȼ"},
	{"��", "�������Ҳյ�����Դ���ﴬ����ۼܿ�����ƱƷɫ̯ջ"},
	{"��", "�ӿڳ��˸�����������ˮ̥����"},
	{"��", "���ƴ����е��Ļٱг���������������������ײ"},
	{"��", "���㴡��ҵ�ص�����ʸ�������¡ŵʯ��������׼"},
	{"��", "�����ػ�е��������Ʊ�����Ƿ������ճ������������׼���������������ǹȺ����ʦʱ��β������������Ҫ������ԱԵ��������"},
	{"��", "�������"},
	{"��", "������"},
	{"��", "ľ���ѹ�������갸�״�·�Ƿˮ��ϰЧѩԹ��"},
	{"��", "��������ע��"},
	{"��", "����ʳ���Ŀ�����"},
	{"��", "��"},
	{"��", "�����������ػ��絴���߻�����ŭ������Խ��ս"},
	{"��", "����Ц"},
	{"��", "�������ھ�ë�߼�����������"},
	{"��", "�"},
	{"��", "���ϪЧѧ"},
	{"��", "����������˽"},
	{"��", "���������հ�¡��������������"},
	{"��", "����������С�ضȶ˰帻��û����Ѿ�������ĿƷȦȨ��΢Ϊ��������������"},
	{"��", "��"},
	{"��", "��¼"},
	{"��", "��"},
	{"��", "�������кϻ��ʳɻ������Ȩɢѵ��Լ��"},
	{"��", "�ڸ���ʱ����"},
	{"��", "�¾�������æ�䲡�ٴ��绵��������������ɷʻ������������֢����ת��"},
	{"��", "�����۷����ʻ��������"},
	{"��", "��ȡˮ"},
	{"��", "�̱��򽫽񾰿���ī��ʱʹ����Ϊλϯ������"},
	{"��", "�ʺ�"},
	{"��", "��������"},
	{"��", "�����ҽ�����������ѹײ"},
	{"��", "�����ʮʱ�����ܱ��ε�ȶ�䷬�ַݺúκ�������������ǧ����ͷ��������"},
	{"��", "��������׵"},
	{"��", "�����"},
	{"��", "��"},
	{"��", "�����ɻ��η���������ʦУ����"},
	{"��", "������"},
	{"��", "�ȷ�ھ���ĩ"},
	{"��", "��"},
	{"��", "�ݵ��ص������Ʒ��ɨ��˾̳������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�ȹ���������ƶ����Դ��"},
	{"��", "�г���ŷѸ��ؼ�����������������ʳ������������������"},
	{"��", "������įȻ��"},
	{"��", "����ʱ�����̷߳ѷ����۽���ı�����˰ί����"},
	{"��", "¼��������ס����÷��ֹ��ҹ��ź�������ȡ������������Ҫ��"},
	{"��", "����ʵ������Ȼ����Ҫ����"},
	{"��", "�����ʻ���"},
	{"��", "����"},
	{"��", "��ŮԺ"},
	{"��", "���ж���ĸ������λ��"},
	{"��", "����ټ�¼����ʵ��ί����ҪԪ"},
	{"��", "�����̽�����������������"},
	{"��", "��"},
	{"��", "���Ĳ�����칥���Ǿ߿���ͷ������סע��"},
	{"��", "�������������ھ���������żƷ��������"},
	{"��", "ͥ�����òƲ�����԰�����ų����󴫵��׵綡���÷縸�����ƽ̾��Ӿ߾��ĸ��������ʷ����˽��լС������ר��������ҵ��"},
	{"��", "�๤ǿ�����ټ��������˲��ܿ���������ˮ���ϳִ��Ե�෨���ָǸ߸��̺ź񻤼��۽������������������Ȩ����н��ѹӡԪ��ֵ֮������עװ"},
	{"��", "��"},
	{"��", "�������"},
	{"��", "״���ҷ��屽���洼�ȹǻ�������������������"},
	{"��", "����"},
	{"��", "�ҳ����˵���ð������ҩ����װ�ڵİ��綨��������������ɽ��ʹ����˵������������"},
	{"��", "��Ŀ����Ǯλֵ"},
	{"��", "���ι�����������ʽ������"},
	{"��", "��������ʻԦ��"},
	{"��", "Ȣ������ױ"},
	{"��", "�л���"},
	{"��", "����Ӷ��ؿ�������ܻ�������Ʊ������ί��Ѻ��Ժ����"},
	{"��", "�ֶ�ǿ�̾�Ӳ���ؿ��γ��̹������ʵͦ����"},
	{"��", "��������˷�п�����ɽ��ʯ����ϸ����"},
	{"��", "ֽ"},
	{"��", "�ӵ��ϸ���ܾ�϶Ъ������"},
	{"��", "������ҩ��"},
	{"��", "��ְ�챸����̵ù˹ܾ߿�������Ӫ��"},
	{"��", "��������ͷ����"},
	{"��", "�޿�����ɬ��������"},
	{"��", "������ɱ��ʬ��ϸ����թ��"},
	{"��", "��Ĭ"},
	{"��", "��������㶨�ٿ�¼ʰ��������������������"},
	{"��", "��կ��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "ȥѡ"},
	{"��", "����ʰ"},
	{"��", "����������ֱ��д����ƴѶ�����α����ƶ̽ݽ��������ª����������ͼҪԼ��װ"},
	{"��", "��ʡ"},
	{"��", "�����ʳɳ��������̶Ϲ��ü��ӿ���ȡȥ��Ӱֽ֦����"},
	{"��", "��ʰ�ϢС������ѹ�ֳ��ͷ�������������ȥ����ɫ��ʡ����˰����н��Ա����"},
	{"��", "��"},
	{"��", "������������"},
	{"��", "��̤"},
	{"��", "���������"},
	{"��", "���ʶ���֤��ЦЧ���������õط����߹������������ϰ����"},
	{"��", "����λֵ��"},
	{"��", "�в�ʸͷ"},
	{"��", "��������׳����ȫ��̸������"},
	{"��", "������ͧ"},
	{"��", "�����ŵ�����ü������̶��"},
	{"��", "����"},
	{"��", "��μ�������������"},
	{"��", "ˮϪ"},
	{"��", "������������ɰ��ĳ������ض��������û�����ģƺƽ������ί��������������"},
	{"��", "�ֹ̻�����ʬӲֱס"},
	{"��", "������֭��"},
	{"��", "���ٽ��;�������Ŵ�����ʿ˧Ϊ��УҪ������"},
	{"��", "��֭״"},
	{"��", "�����İ��߳Ƕ���������ˮɽ������ڱ�����������������"},
	{"��", "����������"},
	{"��", "��ʯ"},
	{"��", "���ͷ�������Ʒ״ȯ������Ҵ��"},
	{"��", "����������������Ц̨��̳��������ݽ�¼��������ʦ��������ϯϰѧ����"},
	{"��", "������"},
	{"��", "�˹���"},
	{"��", "��ˮ�����䵽����������𼶼۽���ħƵ������Ϣ����ѩѹ��ְ��"},
	{"��", "��"},
	{"��", "ʯϪ��"},
	{"��", "����Ƽ�����ú̿����������"},
	{"��", "�沼���Ͼ�����ƤƬ��ˮ����Ьӡֽ��"},
	{"��", "ͨ���ӻ�����̸�����龯���ʽ��״���������������������渶��������û��������𼯼�����ǮȨ��������˰����������ս֯��"},
	{"��", "����Ұ��"},
	{"��", "�໨ˮ������"},
	{"��", "����Ů������������"},
	{"��", "�ει߹󺩿���������������С������"},
	{"��", "��"},
	{"��", "�趯�;�����"},
	{"��", "��"},
	{"��", "����������"},
	{"��", "��"},
	{"��", "̤�װ屾ӡ���̷���ܼ�����������Ѿ��ֺע��"},
	{"��", "�绫������թ����"},
	{"��", "�ȸֻ���¥��Ĥ��ɫ��������"},
	{"��", "��"},
	{"��", "�Ѹ��ػ񽻾�������˰е��"},
	{"��", "������ʹ��"},
	{"��", "����"},
	{"��", "ʦ����ѧ��������Ա����ְ��ѵ���񰸱޲ĳ̷��������滯���߿�������Ȩʿ����͢ͷͽί������������"},
	{"��", "ĸ"},
	{"��", "������"},
	{"��", "���Ͷ̶�ߺû���������������ǰǿ��������ΪС����Զ��֮��"},
	{"��", "���������������úŻ���������������������������ס������"},
	{"��", "�񴩵׶��̷��Ϳ�¶��Ļ����ʾ��������"},
	{"��", "�������������ͼ����߰ഥ�����ؿڵ��ǹܹ��������ý���������������Ǣ��������ɱ������ͨͷ����������Ӧ��֦��ס����"},
	{"��", "��ϲ������֪"},
	{"��", "�����з��Ǿ�·����ͷ����"},
	{"��", "��μ�����"},
	{"��", "ͼ�ϸ�����������ȡȥȻֹ֫��ס"},
	{"��", "�ַ˻���������"},
	{"��", "ĿԼ��ʡ���ٵ�������������¼����ú������ǰʳˮ����������֧֫����"},
	{"��", "�̹���"},
	{"��", "������"},
	{"��", "���ﾶ��"},
	{"��", "ë"},
	{"��", "�Ͼ�����"},
	{"��", "�׾������"},
	{"��", "���ϻ�ҵ����β�����˾ֽ����˰��̰Ͱݰ���ʲݳ��ɳ���浳��Ӻ˻㾧Ĥ��������ʯʵʶ��Ϊ����������ԵԹת������"},
	{"��", "���ͳ��Ŵ���ΣΧѹԼ���������Ѱ԰�������������������ͺ޻󾿾ƾȿ�����������Ƹ����Ȱ����ɢ����˵��������������ҩ������Ԫְ"},
	{"��", "�ܷ����"},
	{"��", "���߳��������Ļ��ƾ�����������ָ"},
	{"��", "����"},
	{"��", "�˵���"},
	{"��", "���궨����������Լַ׮"},
	{"��", "�����������ʹ�����ݿڿ���Ǯ��������������ծ֧����ס"},
	{"��", "�ܴʿ�������������"},
	{"��", "Ѣ"},
	{"��", "����ʱ"},
	{"��", "��"},
	{"��", "�����⶷"},
	{"��", "��ƽ���"},
	{"��", "��񱭱����������������ͯɽɳʯ�⽱ɫ���Ʊҳǻ�Ǯ�����ֲ��񹤻����鼦�ۿ����������ï��������̳����������ӹ���������"},
	{"��", "������������ҹ����������������������"},
	{"��", "�Ͳ�Τ��"},
	{"��", "��"},
	{"��", "�ż���Ҫ�ȱƱմ����ٸ����ӽ������ڰ���ȱ������"},
	{"��", "���������ݱ�м�������ʯ��"},
	{"��", "�˴漰��������ֻ"},
	{"��", "���������"},
	{"��", "�������޲��ͳ���ȡ�������������۱ƹ����ǳ̻��������˽׾��ƾ�������ȥ��ɽʳʿˮ������ѧ����չվ��ֽ��פ"},
	{"��", "�켽���Ƿ������������������"},
	{"��", "Ʒ������ֹ�ض�������������ҩ��������������"},
	{"��", "���꽼������̴�����������·����ǰ������������"},
	{"��", "����Ⱦ��������ʪʴˮ͸ϴ������"},
	{"��", "��������ְ�ҵ��ܻ�����Ȼʧ����ͷТ����"},
	{"��", "���ж��������ͷ��"},
	{"��", "��������"},
	{"��", "��ҵҵ"},
	{"��", "��"},
	{"��", "����Ƭ��Ө"},
	{"��", "����"},
	{"��", "�Ƕ���������������ž�ǻɽʦϷ������"},
	{"��", "ϲ���Ŀֹ��������Ѻ���̻�½з级�������������̾���������������"},
	{"��", "���������Ʒ�������ĳ�ȷ��ٱ�ϸѡ�λ��⵱��Ӣ����Һ���ȷĸɸ����⺷������������������������ͨ����տ��װ׼"},
	{"��", "����Ӫ���������ְ첿�ȷѹ���ó�ͽ���������������������ʹίγ����������ѧѪ��"},
	{"��", "��֮�ܼ���Ȼˮ̨����"},
	{"��", "��ֱ������ѷ�����ٹ�������������Ȯʾ����˾̽��ѶԱ��"},
	{"��", "��ɫ��µ�ۿ���Ľ����ɽ��������"},
	{"��", "������׵"},
	{"��", "�����ĵ�ۺ�ž���������Ĭ̬����������ֹ��"},
	{"��", "�ؽ��������������"},
	{"��", "����"},
	{"��", "ͷ��"},
	{"��", "����񰮰���ҵ�����سƷ��ؾ�Ľ��"},
	{"��", "��"},
	{"��", "η��лף"},
	{"��", "���ܿ���Ƭ����"},
	{"��", "������ֱ"},
	{"��", "��"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "���Ȼ����δҹ��"},
	{"��", "��ɶṺ��Ͷ��ѡ����"},
	{"��", "�������ֵ��"},
	{"��", "��"},
	{"��", "��������̬"},
	{"��", "��ס"},
	{"��", "�쾹"},
	{"��", "������׷��ϼ�������"},
	{"��", "�˻�"},
	{"��", "�𲡴�򾭾���Υ����Զ"},
	{"��", "ʦ"},
	{"��", "�ɴ�ι������ݿ�����ƷǧȪ��̨������������"},
	{"��", "����¥ƿ���걭�˰ɰ�ϯ�����������������ౣ�����������ĸŮ��ǮȪɫ��Ͱͽ������������"},
	{"��", "�����˼��������Ԯ�������Ǳ����ȹ�����������������"},
	{"��", "�������˰�����������ò���ƴ��ض����ۺû�������ʱʽ������ҵ��Լծַ����"},
	{"��", "��"},
	{"��", "��������ĸ"},
	{"��", "����ȡ"},
	{"��", "ҵ��������ҽ�ʹ˴��ض�����̽�ľ��������λ��ѧ��Ҫ������ְ��"},
	{"��", "��"},
	{"��", "����������Ʊ������Ѻ��"},
	{"��", "��"},
	{"��", "������סȻί���ζ๦�Ҽ�����ʿ����ӹ��"},
	{"��", "��"},
	{"��", "�����ټ�������������"},
	{"��", "����"},
	{"��", "����"},
	{"��", "��������Ŀ���챨�����ز����붯�����߼Ҽ���ǹ����ͷ��Ҫծֹ"},
	{"��", "ɥ"},
	{"��", "���ϻ��ͶĹ��������£����ͷ��"},
	{"��", "�������⸶�߽�����"},
	{"��", "����ƴ��˵���ʵ��˵��Ϥ��"},
	{"��", "�����ʯ������ֽ�����¹������ͷ��з�������"},
	{"��", "�屸��������"},
	{"��", "����"},
	{"��", "�ݵ���ľ"},
	{"��", "��ȫ"},
	{"��", "�����������"},
	{"��", "��"},
	{"��", "���䳡�춾������Ŀ��ʹ����УԺ������������"},
	{"��", "������˰��Ѫ������"},
	{"��", "����"},
	{"��", "��������"},
	{"��", "����������"},
	{"��", "������������ֽ��������"},
	{"��", "����"},
	{"��", "��ȡ"},
	{"��", "��"},
	{"��", "����"},
	{"��", "ǿ"},
	{"��", "ʿλ"},
	{"��", "���������"},
	{"��", "�Ķ������������ϷǼƾ�����Ȼʤ������ѡ����ս"},
	{"��", "����"},
	{"��", "�������֢����Ե��ʱڲ��ų������غ����Ѿ��������·����������Ʒ��ɫʳ��������ѧ��������"},
	{"��", "�ȷָ���ӿ���̯δ����Ӧ������մ"},
	{"��", "������˿����"},
	{"��", "��"},
	{"��", "�ӻ�������ί���˷�����ѵҽ��Ӫ�����ٳ����������ѷ�۸蹤���ٹ��Żջ����ͽ��羯����������Ʒ������Ȩ��ʦʿ��ͳ������Уе������Ԯ��ְ����װ��"},
	{"��", "��Ȩ������"},
	{"��", "������"},
	{"��", "�Ľ�����������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��¡ʲ��"},
	{"��", "����"},
	{"��", "Ƭ��������ʽ��ͨס����"},
	{"��", "��Ѫ֨"},
	{"��", "��������չ�����ᴴ����ʼ��֧��ҵ��ѧ��������θͥͨͷˮ�з�����ƽĻ���ʵƵ���ٱ겥�ǳ��������ɶ��˶������⸰�ݹ��������Ļ�۽���־�οѿڿ�������������·������������Ʊ��ǹǻ��ɽ��ʾ����������������ԪԴ��իս��"},
	{"��", "��"},
	{"��", "ģ����"},
	{"��", "��������"},
	{"��", "Ȼ̾��"},
	{"��", "�������Ǻ�ͷ����ӡ����"},
	{"��", "���������"},
	{"��", "����̽��������"},
	{"��", "��"},
	{"��", "�񵶵������Ϸ���ȥɱ������"},
	{"��", "������û��屨�ⲡ�ɳ����������궮���˹ٹܹ߼ҿ�������������������ȥ��������̨ͷ͸ͼ����Ϸ��Ѻ��������������"},
	{"��", "�ص¸��ѽ�������̩��"},
	{"��", "��"},
	{"��", "�˰�����"},
	{"��", "���վ����鰩���粡�ж����Ǹ溮�����������˰����ԭս����"},
	{"��", "�ܺ���"},
	{"��", "ͷ"},
	{"��", "���ڲ����������֤ȡ�鳡���ټ�������������������������"},
	{"��", "������"},
	{"��", "��¯��Ѽ��"},
	{"��", "�����ߵ��£ɽ��ס"},
	{"��", "����������"},
	{"��", "��"},
	{"��", "����˯ͷ"},
	{"��", "��"},
	{"��", "ѧ��Ŀ������Ա��𳤴�ü��ʽ̾�����ίϵЭ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�԰��������ſ��п�������ϧ�ɱȱɱ䲻���ܵõ�����ַ񹩹۹󺹺ú޾�����������������ȡȼ��ʹ��̾ηνϲЦ��Ҫ������԰��֪"},
	{"��", "������"},
	{"��", "�����Ƹ�������¡��ǿ����"},
	{"��", "¼�ǿ��ְ屡�ɳ����Ⱥۻ�������д��ӡ����"},
	{"��", "���˹ۻ��˳������ճ����ص�ӷ���������������Ʊ������������λϯջ��"},
	{"��", "�����ұ����ı����̼��Ŀʱ˰��ҵ����"},
	{"��", "�»�����"},
	{"��", "�ض�������ֳ"},
	{"��", "��������̸"},
	{"��", "��������ľƭ��"},
	{"��", "����"},
	{"��", "����׸����˽����ǰ�ǳ������ض�����ѹ뺣���Ż��Ž�����������ƿȱ��̸Ͷͷλ������Ϯ϶��������������ս����"},
	{"��", "�����������ž�"},
	{"��", "ȸ���������̾���������϶����"},
	{"��", "�Ʋ�ʸ�ɼ�����"},
	{"��", "���ſ�ͷζ���︣���ź������Ű�ˮ��Գݳ��������¶�����ݼ����Ǿ���������ǻ������ʵ����������������"},
	{"��", "���ֵ������ּ��ɽ�����Ǯ��ȥɱ��ѹѺס��"},
	{"��", "��ǻƼŽ߾�ľ��ɬ����ˮ��ήҶ֦����"},
	{"��", "���ӳ����Ž�����������"},
	{"��", "�ĺ���������ʹͷζЦ������"},
	{"��", "��"},
	{"��", "�����Գ��������ɹ����ƿڿ���Ȱɬˮ˼������ѧ����ս��"},
	{"��", "���к�����������"},
	{"��", "�ش淿����"},
	{"��", "�����ܽ�ȹ������������"},
	{"��", "�󽱿˿�ҫ����"},
	{"��", "��̨"},
	{"��", "Խ�����ȹ���������������ʡ"},
	{"��", "����ú"},
	{"��", "��"},
	{"��", "�ֵ��ݵݻ�������ͳ����й�����������ͧοѶҪ������"},
	{"��", "�������Ķ��ݱ߳����´�����������Ƶ��ˡ��ο��ԣխ�"},
	{"��", "�������ʽ����"},
	{"��", "����"},
	{"��", "�绶���������������ŷ���ŭ����̬ͽ��ϲ��ХЦ�����������"},
	{"��", "�ܿ�ͼѡ"},
	{"��", "����"},
	{"��", "��ز�������Ǵ�����������Ȫɰɽʯ����ҵ����"},
	{"��", "����Ұְ"},
	{"��", "��"},
	{"��", "��������Ƿʴ��"},
	{"��", "��"},
	{"��", "Ȼ����"},
	{"��", "��һ�߲������֪̽��"},
	{"��", "���ӻ�"},
	{"��", "����"},
	{"��", "��ΰ����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��ɫ"},
	{"��", "�ܾ���ɢ����"},
	{"��", "��"},
	{"��", "���������ɽ����"},
	{"��", "����"},
	{"��", "���Ŷٶ򷦻󾳾��־������ס"},
	{"��", "�Ż�"},
	{"��", "���󽨾���ɢ��ӡչ����"},
	{"��", "��"},
	{"��", "�𲽴¶�������"},
	{"��", "��"},
	{"��", "�����������������������߻ؾ������£��Ʊƽ��ȥ����������ϡ����ס��"},
	{"��", "����"},
	{"��", "��ʻƾ�Ⱦ����ֽ��"},
	{"��", "���೦÷����"},
	{"��", "����"},
	{"��", "����"},
	{"��", "��������"},
	{"��", "Դ���������ؼ��ɱ����˵��õ緸�ø幥���������������������·��ȥ������˵��ͷ����������"},
	{"��", "��Ƥ��ծ��"},
	{"��", "����������ɫ����ͼ��"},
	{"��", "�˼�Ŀդ"},
	{"��", "���ؽ�·����ס��"},
	{"��", "��ӿ���̳Э����"},
	{"��", "ɺβ"},
	{"��", "�𷻻���Ϫ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "Ȩʤ"},
	{"��", "ʤ"},
	{"��", "�浡�ö躺��ɢ��"},
	{"��", "����"},
	{"��", "��������������"},
	{"��", "����������������ȡɱ������"},
	{"��", "��"},
	{"��", "ͷ"},
	{"��", "����������Ȯ��"},
	{"��", "����"},
	{"��", "��Ůò��ƽ��"},
	{"��", "��������"},
	{"��", "�峱���ѻ���������ͷ����"},
	{"��", "����Ǯȡ��"},
	{"��", "�������ʷ��񷽸Ĺ����ݽ̱����ٿ���µ��ģ��������"},
	{"��", "�����Ʒ��̼ǿ�������ɧ��"},
	{"��", "ʦʵ�Űִ󹫼����鱲���������ǳɵܵ�����������������뽫������·��ĸ������ũ������ɮ��ʽ������˧��ͷ������������С��үӥ��Զ������ׯ����"},
	{"��", "��"},
	{"��", "������ӡ"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "԰�۰����Ȥҵ��ӵöӸ��и�迭��������ƽ��������Ⱥɽ������ʥ������̳����������������"},
	{"��", "����������������ܻ�������ŵ������ͬ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�����������Ƽӽ�������������׸"},
	{"��", "��"},
	{"��", "�ʹ���̨"},
	{"��", "����"},
	{"��", "�ȱ�˴�Ŀ������ͬ����"},
	{"��", "�ɳ��Ϻۻ�ˮ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��������������ˮ̸��Ц�س���繬���������ý����Įů��Ƨ��Ȫȴʳ��������ս"},
	{"��", "����"},
	{"��", "����ɽ��԰"},
	{"��", "���۹�������"},
	{"��", "��"},
	{"��", "�ϻ�ҿ�������ȥ��ְ����ӹ������ݾ���Ⱥ��ɢɧ��ϯ����У��������"},
	{"��", "��"},
	{"��", "�������·������ǹ��ƿƲǳ������û���ҿ���·����˳ͷ��ѧӦ��"},
	{"��", "�ױ����������������˹����Ԩ������"},
	{"��", "�氺�߳��̸۸�������Ū��ˮͷ��Լ��"},
	{"��", "��"},
	{"��", "ò������Ʒ�ݰ����������ڼǽ̽ڽ���ñƸȯ������������������"},
	{"��", "��"},
	{"��", "����֦"},
	{"��", "����"},
	{"��", "ɫ��"},
	{"��", "����ˮ̨"},
	{"��", "��������������"},
	{"��", "��ͼ����־"},
	{"��", "ʯ����"},
	{"��", "ʷ�̴δ����ٽ쾡��������������ʱ��"},
	{"��", "�ú�����Ϣ�״����ü���»��������Ǯ��������������������Դ"},
	{"��", "��"},
	{"��", "��پپ�������������֤��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�������巽�̰������µض����﷨�������������������ʱ��˵��ί������������ҵ��־ס"},
	{"��", "��״��"},
	{"��", "��Ѫ"},
	{"��", "����"},
	{"��", "�������۴ټ����ؿ�ż����Ȱʿͦͼ��ѧս��"},
	{"��", "ϵ�����˺�����Ӫ����ɴ���ӷ��ủ�������Ἧ�ӽ�������������������ͨϯ������չ������"},
	{"��", "�����ӽ�����æ������"},
	{"��", "�ػ���̨����"},
	{"��", "�ܳ��ǳɴ������ӷ��˹�źϺ�������������ƪƽ����ɽ��������ʤ����ͨͬ��ҹ������սׯ������"},
	{"��", "��"},
	{"��", "�ܼ۽���������"},
	{"��", "����ϧ��"},
	{"��", "Դ��"},
	{"��", "Ļ��"},
	{"��", "��"},
	{"��", "ɫ����տ�������Ƥ��������"},
	{"��", "������������"},
	{"��", "������ĸ������ջ"},
	{"��", "����������ͭ������"},
	{"��", "ϰ���ɴ﹦����ȭ����"},
	{"��", "ʳ�ֲݵ�ۿ���Ʊ����վ����"},
	{"��", "�˲�۰象��Ϲ���������ɡɽˬˮͤЬ��"},
	{"��", "����ɽף"},
	{"��", "��Ե��߳��෽�ۺû��ҽ��ÿ�������������ʦ������ҩҽ��֪��"},
	{"��", "�����������뱶�ʱ߱��ε����ص�˺����Ἣ���ռ��������������ȫ��ͷ��������������Ժ��ֻ������"},
	{"��", "��������ʶȻ�����������"},
	{"��", "��ɹ"},
	{"��", "����ȹ����ƬƱ������"},
	{"��", "�ؽ�"},
	{"��", "������"},
	{"��", "�����ի"},
	{"��", "����"},
	{"��", "���̷���Ч����"},
	{"��", "ԭ"},
	{"��", "����"},
	{"��", "����������������Դ"},
	{"��", "�ݵ�"},
	{"��", "��᰸���ö���ȴȻ������Ը"},
	{"��", "����"},
	{"��", "��"},
	{"��", "������"},
	{"��", "�������������������"},
	{"��", "�����ɳ������ӹ�����ǿ��Ϊϯӡ"},
	{"��", "���ۻ�������϶"},
	{"��", "���Ů��ʿ������"},
	{"��", "�ȼ�Ʒ��������"},
	{"��", "����ǹȡȮ����ͷ��ӥװ"},
	{"��", "����Ŀ"},
	{"��", "ҵ��߱����������غ������ľ����Ȫ������Ұ��԰������"},
	{"��", "�ʹ����"},
	{"��", "ʱ��Σ�簲���߱����ҳ��������ڷ纣�ü콭��ġĩ������ȥ˯��ͷϪ��Ԩս��"},
	{"��", "�����ҽӽ���������"},
	{"��", "��Ƭ��"},
	{"��", "�Ͳ���ʪ��ԡ"},
	{"��", "��Ȼ��"},
	{"��", "ϧ��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "���õ�����ȹ�������������Ǯɢʱʳ��ͷ����"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�����ٺ��ݿ�����Ű����Ѵ��־"},
	{"��", "�������㳵�����йǹ����ܽ���ý��ǰ������ͨλϬЧ����ҩ��֥��"},
	{"��", "Ĺ��԰"},
	{"��", "����"},
	{"��", "����������ضӺ����ػ�̽���տڿ�·����ȡ����ͷ����������������������"},
	{"��", "���Ӿ�������ѡ����"},
	{"��", "�˰�������������"},
	{"��", "��������"},
	{"��", "����"},
	{"��", "��"},
	{"��", "���ǿ���"},
	{"��", "��ѧ���������������ɴ���׸�����������ȡ����������У��Ӱ����ְ����ספ��"},
	{"��", "��������ԣ��ܭ��"},
	{"��", "��ͨ��ˮ������̸�����Ѫ�����Ǵ��ܵ������Ź����ױ仨�ؽ�������¶��å����ɳʧ��������������������к��ө����תݺ"},
	{"��", "����ü����������Ҷ����֦�"},
	{"��", "һ��ͯ�ںϽ�����ٳ��ȸ�������ǧ������ʮͨ����������"},
	{"��", "��������ͷϺ���ۺ���������Ȫ�߿���̶���Ź��鴲�ƶ�������Ů����ɽ������Ѩ������"},
	{"��", "����"},
	{"��", "����ͳ����"},
	{"¡", "�ذ����¶���¡����ʢ������"},
	{"¢", "��"},
	{"¤", "����ɽ��"},
	{"¥", "��㴰������������Ⱥ����̨����������"},
	{"¦", "��"},
	{"§", "��"},
	{"¨", "����"},
	{"©", "ʧˮ�����綴���⾡��˰����"},
	{"ª", "������ϰ��"},
	{"«", "�����έ����"},
	{"¬", "�Ȳ�����"},
	{"­", "��"},
	{"®", "ɽ"},
	{"¯", "���һ�����������"},
	{"°", "����"},
	{"±", "çˮ��ζ"},
	{"²", "��"},
	{"³", "��˶�çɽ��Ѹ"},
	{"µ", "µ"},
	{"¶", "��׳��׵������ˮ����ͷ����Ӫ��"},
	{"·", ";�̵߳ƶηѱ߱꾶�Ͽ��ɹ�������ä��������������"},
	{"¹", "���ǹȽ���Ұ"},
	{"º", "����"},
	{"¼", "ȡ��������Ӱ��������"},
	{"½", "�ط��ӾӾ�·������������ս"},
	{"¾", "��ͬ��"},
	{"��", "����������"},
	{"��", "�Ͻ�"},
	{"��", "���οͰ鳤�̵�ѹݾ�������˳;"},
	{"��", "����������Լ"},
	{"��", "����"},
	{"��", "����"},
	{"��", "��ʦ����ʫ��"},
	{"��", "���Ӷ���Ȼͬ��������ֱ"},
	{"��", "����Һֽ"},
	{"��", "ɫ��ˮҶ���ݲ赺�Ƶطʿ���ñ��ѿҰ������ԭ������"},
	{"��", "��"},
	{"��", "����ʯ����"},
	{"��", "��˵��������д�е��ɹ���������Ū��������������"},
	{"��", "�ض����ȡ"},
	{"��", "ͼ����ע��ȥ��˵ͬ΢Ϊ����"},
	{"��", "�ബ��̥���ɷ��ڻ��ػ�������Ȧ��Ь��ѵ��ֵ��������"},
	{"��", "������"},
	{"��", "���������ɥ��Ϊ��"},
	{"��", "̳�����ƴ��Ե���ϼ�������˵������ս����֤����"},
	{"��", "��"},
	{"��", "����ñĸ˨˿����"},
	{"��", "���������Ʋ���ɹ�����������ɡɲɽ����������֯�����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��¶����"},
	{"��", "��������껨Ҷʵ��ܰ�ʲ���ɵ��õص㺣�Ŀջ���įĻ����ȥ��ˮ������ѡӢ������"},
	{"��", "ɼ����"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "������"},
	{"��", "��ȸ��������ҩľ��Ǵ������ķ绨����ɴ��ʡ������"},
	{"��", "�����"},
	{"��", "��ͷԪ����"},
	{"��", "�������"},
	{"��", "·������β�������ﵶ�ƶӷ��򹫹Ӻźջ����׽žǾԿ�������������ƥƨ��������̫��ͰϷ����������"},
	{"��", "������"},
	{"��", "�ص���û������ͷ��Թ��"},
	{"��", "�˳ɴ��������������ؼҼ۽�����ȥ����ͨ����������"},
	{"��", "���ͼӿ�������ѿ��"},
	{"��", "������������ʸ��Թ���ۿ�ŪǮ����Ц����������"},
	{"��", "����������������"},
	{"��", "�����嶯����"},
	{"��", "ƭ"},
	{"��", "ͷ"},
	{"��", "�������ɺ������"},
	{"��", "����ǻ������Ŀ�ڷָ��������ص��ض������������ͷ������Ա��"},
	{"��", "����"},
	{"��", "����������"},
	{"��", "�岽������˵��"},
	{"��", "�����Ĳ���������̸��������"},
	{"á", "��"},
	{"â", "������"},
	{"ã", "ãȻ"},
	{"ä", "Ŀ���Ӵ�㶯������������"},
	{"æ", "��������µ������"},
	{"ç", "�Է�ԭײ"},
	{"è", "����������"},
	{"é", "�ݲ޶ܷ���®��̨��"},
	{"ë", "��ձ�Ĳ��ʲڶ����ӿ�����¿ķ����ƤƬˢ̺����з������"},
	{"ì", "��ͷ"},
	{"í", "��"},
	{"î", "��î"},
	{"ï", "����ʢ"},
	{"ð", "�ƳƳ��ճ����Ż�������������Ȼʧ������������"},
	{"ñ", "����"},
	{"ò", "����������"},
	{"ó", "Ȼ��"},
	{"ô", "������"},
	{"õ", "��"},
	{"ö", "��"},
	{"÷", "�����عغ컨������ɽ����"},
	{"ù", "���������ζ��"},
	{"ú", "��¯����Ŀ���̿��м��Ҥ������"},
	{"û", "���з���������û��������������"},
	{"ü", "��ɫ����ëĿ����ͷ����"},
	{"ý", "����������"},
	{"þ", "ɰ"},
	{"ÿ", "����λ����ʱ���ε��ַ�����ʻؼ��Ҽ������ÿ��������̨����������"},
	{"��", "�������������۾���ζʳ����Ůɫ�����ޱ�Ų���Ƶµķ����ָи�Ӿ��òü��������Ũ��ʽ��̸ͼѧ������Ӣ������Ԫչָ��"},
	{"��", "������"},
	{"��", "̬����"},
	{"��", "��Ʊǰ�����ƿ������Ͱ崰���Ƶڶ����������컷��������������������¥·����ǽȯ��������˨��ͥͽ���������"},
	{"��", "�޳���������ɧ��ͷ"},
	{"��", "��������ѿ"},
	{"��", "�γ��Ż콭��������ƭɽ����������"},
	{"��", "��������ԱԼ��"},
	{"��", "��"},
	{"��", "�Դ�����������������Ȼʿ����Ϯ������ײ׷"},
	{"��", "�������ü���¶������������߽��"},
	{"��", "��������������������"},
	{"��", "��"},
	{"��", "��֮��"},
	{"��", "�����˹����ʧ�ź����ü����"},
	{"��", "��"},
	{"��", "�ʷ�·����ã������;����ҩ��ס�"},
	{"��", "����������"},
	{"��", "������������ɢ��"},
	{"��", "�ֵ극�۸�۾���������¬Ȫɫʳ������ѩ֬��"},
	{"��", "���鱾������³ʷ��"},
	{"��", "����ʳ"},
	{"��", "��"},
	{"��", "������̸̽"},
	{"��", "�佤����"},
	{"��", "�ղ���ȷ��÷�溯������������ıʵҽ��ԼԿ��ֲ����"},
	{"��", "�������Ļ�ũǩ��ɴ����������ֽ֯��"},
	{"��", "������������"},
	{"��", "�ѳ��÷���Ʊȥ����˰��̸��������������ְ"},
	{"��", "����ǿ"},
	{"��", "���黳"},
	{"��", "����Ŀ����ǢĤǰɫɴ�ݷ۲���ڳ³ʵĶ�溣���ս��߿�����ò������Ƥ������������˪̸����л��������ֵֽ������"},
	{"��", "������ľ������ͷ��"},
	{"��", "����ġ��ͼд"},
	{"��", "׼"},
	{"��", "��"},
	{"��", "������"},
	{"��", "ã��С"},
	{"��", "������ף"},
	{"��", "�����Դ�������������������ҩ��������տּ��"},
	{"��", "��"},
	{"��", "�����𼣾�������������"},
	{"��", "���������Ӫ�þ����˱��������߷��﹤���ͼҽ���Ů��Ȩ��������ί��ѡ��ҥ��Թ����լ������"},
	{"��", "��"},
	{"��", "��л۽���"},
	{"��", "�������ʡ"},
	{"��", "������ȷ��֪��������쳯��������µư����ȶ����������������������������������������ʾ˵������ϸ��ѧ����֤־��������"},
	{"��", "��"},
	{"��", "�ѷŷ�н�ǹлԩ"},
	{"��", "���мǿ���"},
	{"��", "��Ƭ����Ŀ�������������ǲ˲������ʴζ��ַݺż˼ҽ��ǽ̽нھƾ���������¼��ģƪ������ɫɽʤʦʳʵʿ��������Ϊλ����У����ҽ����������"},
	{"��", "��������������������"},
	{"��", "����"},
	{"��", "����ͷ�Բʵ��׺�����������"},
	{"ġ", "����д"},
	{"Ģ", "��"},
	{"ģ", "��淶�º��߿���ʽ������ѹ��ӡ����"},
	{"Ĥ", "��Ƭ"},
	{"ĥ", "����ɳ�����������ĺ�����ī��ƽ��ɰ����������"},
	{"Ħ", "���еǶ�����������ڭ����"},
	{"ħ", "���������羵������ͷ������צ"},
	{"Ĩ", "����ȥɱɷ��"},
	{"ĩ", "���˽�����·����������βλϯҶ��"},
	{"Ī", "������ֲ�����ܹ�������˵��"},
	{"ī", "���ʺкڼ��Ҿ�����ˮ��֭����"},
	{"Ĭ", "дȻ�ϰ�������Ĭ����˼��"},
	{"Į", "�����ĵ�Ȼ��"},
	{"İ", "·��"},
	{"ı", "�÷�������������ȡɱ��ʿ��˽ְ"},
	{"Ĳ", "����ȡ"},
	{"ĳ", "���ظ���ĳ����Щ����ʱ������"},
	{"Ĵ", "ָ"},
	{"ĵ", "����"},
	{"Ķ", "��"},
	{"ķ", "ָ"},
	{"ĸ", "��Ů�׹��󼦽̾�����ϵУ��Ѽ����Ӥ������"},
	{"Ĺ", "����Ѩ԰��־"},
	{"ĺ", "������ɫ��"},
	{"Ļ", "��������"},
	{"ļ", "�����"},
	{"Ľ", "����"},
	{"ľ", "���ϲİ������񴬴��񷤷������ܽ�ż���̿�����������ƬȻʯ��̿����Ͱͷ����м��ҵ����դ����׮��ګ�����"},
	{"Ŀ", "���¼ǰ���ζû���������ѣ"},
	{"��", "��"},
	{"��", "�ݳ��ѵظ���ţ��Ⱥ��ʦͯ��ҵ"},
	{"��", "��Ӣ"},
	{"��", "�������߶���������ȥ����ס"},
	{"��", "�߶�������������λЩ��һ��߸"},
	{"��", "��"},
	{"��", "ô�����ζ�������ĩ��ʱ��Щ��һӢ����"},
	{"��", "�����������Ƹ��˰�����"},
	{"��", "������"},
	{"��", "�跿����������ţƿ��ͷ����"},
	{"��", "���ĺ���������ĥ����ҩ����"},
	{"��", "����"},
	{"��", "�����������������߲�����䴨�����˷Ƿ�۹���������������������������ŷƽ����ɳɽ����ͨͶγ����Ѳ������Խ��������"},
	{"��", "��Ů��װ��ʿ���޵��Ӷ������������ģ��Ȩ��ɫ��˫����Ӥ������"},
	{"��", "�õ㶮����Ϊ�ȹֹسԴ��쿴�����Էְ������������ܽ⿰��������ɫ����˵������������������"},
	{"��", "����"},
	{"��", "����"},
	{"��", "�����Ϻ��ʽ������������Ĥ��ѧ��֭��"},
	{"��", "�޻�ŭ��"},
	{"��", "���в�������������������"},
	{"��", "���"},
	{"��", "����������Ʒ��ο��ɺӵ���Ӧ��صܶ��������˹��������ĺ˺������齭����½����������ĤĻǶ����������������������������Ұ������������ծս��֤������תװ��ڧ"},
	{"��", "������ѿҶ"},
	{"��", "���������Դ�䶯��˵���Ľ���ȡ����ʿ��Ϊ����"},
	{"��", "����"},
	{"��", "������ڵ񹤹������ҽ�����Ţ��ɳ��̶������ש�"},
	{"��", "�����ɹÿ���˹"},
	{"��", "�춨����;���������"},
	{"��", "���Ǵ��ľͿ�����"},
	{"��", "����"},
	{"��", "��ζ"},
	{"��", "������ת������羳��ˮ����"},
	{"��", "���д�ˮ��"},
	{"��", "������"},
	{"��", "��Ȼ��������״����������ɳ��ε׷ַݸ�ź󻪻���ټ����ڽ��������������������������ĩ����ǰ������������ͷϢ����нҹ����"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������������ͷ��߶"},
	{"��", "������̥��"},
	{"��", "�ɻ�����"},
	{"��", "������������ǹ���������"},
	{"��", "������Ƶ����ͰҺ"},
	{"��", "������ס"},
	{"��", "����"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "Ц"},
	{"��", "�ɹ̽������˼��֬������"},
	{"��", "�����º;��ɿ�������Ը��"},
	{"š", "��һ������"},
	{"ţ", "�̰�����������ٶ��ƽǽ�����ë����ƤȺ������βһ������"},
	{"Ť", "�򶯽�������������ת"},
	{"ť", "��"},
	{"Ŧ", "����Լ"},
	{"ŧ", "����"},
	{"Ũ", "���赭�Ⱥ���������������ױ"},
	{"ũ", "ҵ���������������ػ���򸾸������Ҿ��߿ƿ�����æóū��ʱ������У��ѧҩ������רׯ����"},
	{"Ū", "�ó��ɳ��������öϷ�������Ȩɢ�����������"},
	{"ū", "�Ź����������"},
	{"Ŭ", "��"},
	{"ŭ", "�����"},
	{"Ŭ", "��"},
	{"ŭ", "���ɶ�����"},
	{"Ŭ", "������"},
	{"ŭ", "�źź����Ŀ������߳"},
	{"Ů", "����ʿ�Զ������޵��ܶ���������ʽ�����������ū����Ȩ��ɫ��ʬ������УЬ������ӤӶ������װ�����"},
	{"ů", "�����ͺ���¯��ɫ��"},
	{"Ű", "��"},
	{"ű", "��"},
	{"Ų", "�����迪������"},
	{"ų", "����"},
	{"Ŵ", "��"},
	{"ŵ", "����������"},
	{"ŷ", "������½����ķʽ��Ԫ"},
	{"Ÿ", "��"},
	{"Ź", "������"},
	{"ź", "��˿����"},
	{"Ż", "������"},
	{"ż", "��������Ȼ������"},
	{"Ž", "��"},
	{"ž", "ž"},
	{"ſ", "��"},
	{"��", "������ǽɽ������"},
	{"��", "�׶�"},
	{"��", "������������������"},
	{"��", "�����հ�����������Ƭ����"},
	{"��", "���й��ˮ�������ӷŹǱȲ鳡���ѳɳ�������༷�⿪��������������ǲ����ͷ����Ϸ����ӡ��"},
	{"��", "����ż۾�¥λ����������"},
	{"��", "��"},
	{"��", "��������Ը�����ǲ��ͷ��ϵԱפ"},
	{"��", "�ȵǸ�����̸��ԵԽ��֦"},
	{"��", "����"},
	{"��", "������ѷ��ŹȻ���������ݾ������ʯ������ϥ��������بڵ"},
	{"��", "ʯӢ"},
	{"��", "ͷ��"},
	{"��", "���𴦶��Ϲپ���������"},
	{"��", "�䵳������������ͽ"},
	{"��", "��Ȼ��"},
	{"��", "�߲�ۼ���������ͨϵ֤֦ע��"},
	{"��", "�ն���"},
	{"��", "�����⿪��ê����������"},
	{"��", "��Х"},
	{"��", "������"},
	{"��", "�����Ӻ�һ��¥����̨ͧ������"},
	{"��", "����"},
	{"��", "�����������õ���������ȥ��������"},
	{"��", "�ɲ˲跹ĭ������Ӱ�"},
	{"��", "̥����"},
	{"��", "ѵ����ֲ����"},
	{"��", "�����������ǮЦ"},
	{"��", "��ļ޾ƿ���������ͬЦ��"},
	{"��", "�ϼ��ױ������Զ�����ɽ�����żɫ����ͼϷҩ��������"},
	{"��", "������"},
	{"��", "��Ȼ"},
	{"��", "Ȫ��ˮ��ͷ����������𽦿�ī������Ϳ����"},
	{"��", "�ؾ�ǻ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����������"},
	{"��", "������"},
	{"��", "��������"},
	{"��", "����"},
	{"��", "ɰ��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "�ѱ�����"},
	{"��", "�ǳ�"},
	{"��", "������ס����"},
	{"��", "���ڵ���������������ͷײ"},
	{"��", "����"},
	{"��", "˪"},
	{"��", "��"},
	{"��", "����׼���Ų����ε㶷���Ĺ��˻ػ�����ʾ������עת"},
	{"��", "��Һ�׼��¶����"},
	{"��", "��ն�˲Ĳ�ͷ"},
	{"��", "��"},
	{"��", "����"},
	{"ơ", "��"},
	{"Ƣ", "��θ����"},
	{"ƣ", "��������������"},
	{"Ƥ", "���������´�Ь�޲������Ļƻ��м���ë��Ĥ������ѥ����֬����"},
	{"ƥ", "�з�����"},
	{"Ʀ", "��"},
	{"Ƨ", "������"},
	{"ƨ", "��"},
	{"Ʃ", "����"},
	{"ƪ", "��"},
	{"ƫ", "��ʳ��"},
	{"ƪ", "Ŀ��"},
	{"ƫ", "�ذ������ͷ��Ϸ�ü���������Ƨƫ����ʧʴ˽̱̻��С��Ҫ����Զִ"},
	{"Ƭ", "����ζ϶�������ͷ��Լ״��"},
	{"ƭ", "�����ƾ�Ǯȡ��ɫ������"},
	{"Ʈ", "������������ҡ����������ƮȻ����ɢ����ѩ����"},
	{"Ư", "�ײ�����������"},
	{"ư", "��"},
	{"Ʊ", "�����۾ݾ���������Դ��"},
	{"Ʋ", "��������"},
	{"Ƴ", "��"},
	{"ƴ", "����������������ͼд��"},
	{"Ƶ", "���ߴ����ȷ�������Ƶ��"},
	{"ƶ", "��Ѫ�����������������ũ�����"},
	{"Ʒ", "�����ֲ賢�¸�ܺ켶��ò����ζλ������������"},
	{"Ƹ", "��������Ϊ����Լ"},
	{"ƹ", "��̳"},
	{"ƻ", "��"},
	{"Ƽ", "ˮ�����"},
	{"ƽ", "������������ʱ�׵Ⱥ���й��ͷ��̴��׵ص��װ嶨�ȷ������ַ��������۽��־������¯����ƽ��������ʵ����˳��̨̹��ͷ��ϢϪ����ң��������ӹԭ��ֱװ"},
	{"ƾ", "�����ݿ�����֤��"},
	{"ƿ", "�׸Ǿ���װ��"},
	{"��", "�Ȳ���ѡ�������г��������㶨�Ϸֹ����˼��۽������Ƹ����˵Ϊί����ע"},
	{"��", "���γ�����Ļ����Ϣ��"},
	{"��", "�ض�"},
	{"��", "����īƤˮ��"},
	{"��", "���ߺüѾþ߾���Ϊ����"},
	{"��", "��������ϱ�����"},
	{"��", "���žɲ������ѷѲư��ܲ��������������������������������������������"},
	{"��", "��"},
	{"��", "��������ʹ��"},
	{"��", "�׸��⿪����"},
	{"��", "�Ǵ򵹷ۻ�־ȿ˿�����ɱ��ͨ��"},
	{"��", "�µ�ǹ쿪·��ƽ��λչ��װ��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "����"},
	{"��", "����"},
	{"��", "������"},
	{"��", "ʵ��׾"},
	{"��", "��ͨ����ȶɷ��ý�������������ѡ��"},
	{"��", "��"},
	{"��", "����ϵд��"},
	{"��", "��¶ɹ"},
	{"��", "��"},
	{"��", "�����俯��ĩ����������Լ"},
	{"��", "��ƭѹթ����������"},
	{"��", "����Ϣ"},
	{"��", "�̹�"},
	{"��", "��������"},
	{"��", "����ǧ���´�¾�¥��������ɫ��ʮ��ϲһ"},
	{"��", "�ҳ�������Ȼ����"},
	{"��", "�ɺڻ���"},
	{"��", "��"},
	{"��", "ʵ������ζ����������һ"},
	{"��", "����־���������ʥʿ��̳������"},
	{"��", "�����ɹۼ�����Ź�����������ıżȤȱ��������̸��ΰ��Ϯ��Ч������Ե־��"},
	{"��", "����·��;��"},
	{"��", "�"},
	{"��", "��"},
	{"��", "�������������Ź���������ȫ����һ��"},
	{"��", "�˺Ž�����ɽ������������"},
	{"��", "������������"},
	{"��", "�����˷�پ�¥¿��ǽʦʿ����"},
	{"��", "���������ݳ̵��ض��ɾӳ����������ʱ���������Ҽۼ���������������ɫ��ʼ����������ͷ����������������Դ����վ���"},
	{"��", "�����Ǹҿ�����ֹֻ֪"},
	{"��", "������ʳ��ؤ"},
	{"��", "ҵ��ܻ�������ͼ��"},
	{"��", "���̳ݵϷ��⺽��ʾ��������"},
	{"��", "���ϻ�Լ"},
	{"��", "��ǽש"},
	{"��", "�Ķȹټ�����������е��"},
	{"��", "����Ŵ�ζ�ܺ�����Ϣ����㴰���ȷ��շ߸׹������ڽ������������¯��������������ǹɫʢ����̬����ѹ��������"},
	{"��", "��"},
	{"��", "��Ͷ��Ȩѧ��"},
	{"��", "�����ƵѸ׻���ˮͧ��"},
	{"��", "������Ȼ��Ѫ"},
	{"��", "��վ"},
	{"��", "��ס"},
	{"ǡ", "�����ǡ������ֵ"},
	{"Ǣ", "�칺��̸ѯ"},
	{"ǣ", "�ֹҳ�����������ǿ��ͷ��������"},
	{"ǥ", "��"},
	{"Ǧ", "��ʵ�����ӡ��"},
	{"ǧ", "�����������˽���źտ���������Ԫ��"},
	{"Ǩ", "�������;�ŭ��������"},
	{"ǩ", "����������������ӡԼ��֤��"},
	{"ǫ", "�ƴǴʹ�������ѷ��"},
	{"Ǭ", "��¡"},
	{"ǭ", "������"},
	{"Ǯ", "���Ҳƴ��������Ʊ����ׯ"},
	{"ǯ", "����"},
	{"ǰ", ";���������̨�򱲱۱߳��������ж˶��򺺾��ƿ�������é��������������ȥ������������������������ͷ������ϦϷ����������ҹԵԺհվ������֫��׺��"},
	{"Ǳ", "�ط�����������ˮ��ͧ������"},
	{"ǲ", "��ɢ����"},
	{"ǳ", "���������������ª��ɫ��ˮ˵̸̲����Ц"},
	{"Ǵ", "��"},
	{"ǵ", "��"},
	{"Ƕ", "����"},
	{"Ƿ", "��ծ���˰������ѽ�ȱ����˰����н��"},
	{"Ǹ", "��������"},
	{"ǹ", "���ѱб������˻�������ɱ��������е��ս֦֧"},
	{"Ǻ", "��"},
	{"ǻ", "��"},
	{"ǽ", "���ڽŽ�����ͷԫֽ"},
	{"Ǿ", "ޱ"},
	{"ǿ", "���ֻ������������ձư�����󵵵���е��ȶɶṥ�̹������ǼӼ｡����������ȡȨ������ʢʹ������ѹӲռ��׳��"},
	{"��", "�־Ȱ��׶Ṻ��������̲��������������ռ��ע"},
	{"��", "��թ�������������������"},
	{"��", "��Ȼ��"},
	{"��", "���տ���������ͷ��"},
	{"��", "���������"},
	{"��", "��ľǨʯ��װ"},
	{"��", "������Ӿ���������"},
	{"��", "���Ը��ɼƾ�����˼����"},
	{"��", "������"},
	{"��", "����"},
	{"��", "�α�"},
	{"��", "����Ƥ"},
	{"��", "��"},
	{"��", "��ʵ�ϻ��������Ϸָ�ǼɽῪ����Ī��Ƭ��������������Ҫ"},
	{"��", "��"},
	{"��", "����˵"},
	{"��", "��ų��"},
	{"��", "������ȡ��ϲ��Ц����"},
	{"��", "�ݲ�Ͷ�����Ľ����"},
	{"��", "�᷸����Ȩ����ʴ��Ϯռ"},
	{"��", "����������������������������ʶ���ͼҽ��������������������������������������ˮ��Ե��������"},
	{"��", "���ع۹�����ǻ��"},
	{"��", "���ܼ�ɪ��ʦ��"},
	{"��", "��ܿҿ����������ѧ����"},
	{"��", "��"},
	{"��", "��������ס"},
	{"��", "����"},
	{"��", "����"},
	{"��", "�˷θ���"},
	{"��", "������ɽ�׹ϰ���˲زݴɴ䵺��������������������¥��Ŀɫɬ������ʯʷ��̦����ͭ��Ҷ����������"},
	{"��", "������Ʈ�ʿ칤�������жȷķ縡������ݿ�������������������ȡ��ɴ��������΢������������ӯ������װ��٬"},
	{"��", "��������"},
	{"��", "������б�����ĵ�������Ľ������йк��ע"},
	{"��", "��������"},
	{"��", "�׳�������̸����������ϴ�з��������ղֲ�賡�����������γ������������㸣�߹��ٹ溮�ӻ��Խ��˾����ƿ�����������������ƶǷȪɨʷ��ˬˮ��͢��Ϫ����������Զ����������"},
	{"��", "��"},
	{"��", "�Ϳ�������"},
	{"��", "����"},
	{"��", "�������½ڱ�����ٳ��ии���ַݷ򸾻������ᾳ������ǣ��Ȥɫ��ʫʷ������˼˿��̬������������������ԵԸ����״�"},
	{"��", "��"},
	{"��", "�ٽ̽�������ʾ����ǵ�������Ϳ�����Ǣ����ӧԸսת"},
	{"��", "�ǵ书������ף"},
	{"��", "����������֬"},
	{"��", "���������������ٿ�æ������������;׷"},
	{"��", "�첥���ɶ��ַ�����������ǧ��ɫɽ��ˮҶ���"},
	{"��", "��������"},
	{"��", "����"},
	{"��", "�����Ӹ˸�������������·������������̨��ͯЬ������Ա��֤״"},
	{"��", "������������ȱ�ų����÷��湺�ͻ���̽���ż��ȡȫ����ʤʵ����ͬ����ѧҽ��Ԯս����ְ֤֪"},
	{"��", "����������ͽ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������ͬ����"},
	{"��", "�𳤶ηֺ��򻮼��������ίλ��ׯ"},
	{"��", "�۱۱��ߵ��ȸ����⾶������������ֱ����"},
	{"��", "�ɿ���"},
	{"��", "�Ŵӷ���ƽ��ϥԭָ��"},
	{"��", "���߳��̳�����Ϲ�ǲɢʹа��"},
	{"��", "����"},
	{"ȡ", "��֤�����ñ��ĳ������޷���Ц�ž���������ů����ȥ��ʤ������������ֵ����"},
	{"Ȣ", "����ϱ"},
	{"ȣ", "��"},
	{"Ȥ", "����ζ����"},
	{"ȥ", "����ɲ���������������·����������ְ"},
	{"Ȧ", "�ص���Ȧ��������"},
	{"ȧ", "��"},
	{"Ȩ", "��������˹����λ��ı����ʵ������ΪҪ����������״"},
	{"Ȫ", "ʯˮ̨����Դ��"},
	{"ȫ", "�����ļҵ�����Ȼ��ʡ������Ʊ�����������ಿ�ų�������Ա�Ƴǳ̲��嶼������ûἯ�߽Ǿ�������ò������ƴȨ����ʢʤ������������Ϣ������У����Ժ����"},
	{"Ȭ", "��"},
	{"ȭ", "�����ַ�������ʦ��̳ͷ��"},
	{"Ȯ", "������"},
	{"ȯ", "��"},
	{"Ȱ", "����ͻ��ܽ��������ļ��˵��οѧҵ��ֹ����"},
	{"ȱ", "���ٷ���º�������Ƿ������ʡʧˮ��ϯ����"},
	{"ȳ", "����"},
	{"ȴ", "����˵"},
	{"ȵ", "����"},
	{"ȷ", "����ʵ������ȨȻ����Ӧ������֢֤֪"},
	{"ȸ", "�߳���Ծ"},
	{"ȹ", "����"},
	{"Ⱥ", "��Ӣ�鼯����������ܽ��Ӿ�����Ź����ɽ����С����"},
	{"Ȼ", "�������"},
	{"ȼ", "���յ��������"},
	{"Ƚ", "Ƚ"},
	{"Ⱦ", "���ɸ׻���ɫ������ָ"},
	{"��", "��"},
	{"��", "�������ɸ�������·������λ��������"},
	{"��", "����ˡ����"},
	{"��", "��������"},
	{"��", "����·����Զ��"},
	{"��", "���黨�����������"},
	{"��", "����ˮѪ�������Ű�������𳦹������ϴ����ȷ��˺ӻ�������������������������������ʳ��������Ѷ��Դ����"},
	{"��", "���ȵº�����������"},
	{"��", "��������������������������ŲĲγ��ƴδԴ�����ͻ����ҽܾ������񷸷�����������Ʒ��ȨȺ����ʿ����������ͷΪ��������ѡ��Ӱ��ԱԳԵ��֤��������"},
	{"��", "��������ʹ����ס"},
	{"��", "������"},
	{"��", "����ѡ����̿�������ƾ��������ְ"},
	{"��", "ʶ����������ö����ɾ��������������ͬΪ������֤֪������"},
	{"��", "�߿�"},
	{"��", "��"},
	{"��", "����"},
	{"��", "����Ȼ��δӦ��"},
	{"��", "����ɽ���ñ���������ñ���ҹ��Ҳ��̳������������������������������û������ǰ����ɹ��ʳʴ��ͷ��Ϣ��н������ԪԲ����־��"},
	{"��", "��װ"},
	{"��", "ë"},
	{"��", "��"},
	{"��", "�ɳ�ǵ������������»������������ҫ��"},
	{"��", "��ͺϻ����Ǣ������ͨΪ��"},
	{"��", "��ϻ��ӽ���¯����"},
	{"��", "��㶴�ϻ�����Һ"},
	{"��", "�����մ��ù�ò���ɻ������������������"},
	{"��", "��ë����"},
	{"��", "����Ա׸"},
	{"��", "�ɴ��"},
	{"��", "��������������������˳ϸ����"},
	{"��", "ʳ˿����������Ƭ���궡����ţ��Ʊɫ������������֭����"},
	{"��", "�ຬ����"},
	{"��", "�涯"},
	{"��", "�ҽ�����ѧ����"},
	{"��", "��"},
	{"��", "�˹������Լ�����޹ʼ��޾���������������ʵ����ͬͼ����һԸ����"},
	{"��", "����û"},
	{"��", "֭�׳ݷ��幵������������ĸţƷ����ͷ����ҺԴ������״"},
	{"��", "��������"},
	{"��", "��ѧ�Ҿ��ڹɻ�������ϯ���ŻＮ�̶Ӷ������۸�ǻ�����÷��ħ��������������ʱ��˯������΢Χ��Ϣѡ��ҹӪ��Ժ��׸����"},
	{"��", "��"},
	{"��", "����Ӳ���ǵ���ǹܻ��Ž�����ƤƬʽˮ������ϯ������"},
	{"��", "���伮��Ԫ"},
	{"��", "���ݲ��䷼ʿ��ѩ����"},
	{"��", "������������������"},
	{"��", "������"},
	{"��", "�ʷκ���ɫʪ��Ѹ��֮��"},
	{"��", "�в��Ǹɺ���ʹ��Ҫ"},
	{"��", "��"},
	{"��", "������"},
	{"��", "���������ǹ�������ˮ����С"},
	{"��", "�ѽ�������������ˮ����Ұ��"},
	{"��", "�������ɨ��ˮ��"},
	{"��", "��ķ˹��"},
	{"��", "����"},
	{"��", "����������ס��"},
	{"��", "�����̵���Ἶ����ǰ����������"},
	{"��", "�ʰ˰����ǹ��ý�ˮ��˼����������ȱ����ض෽�Ϸָ��Ϻӻἶ�׽��̽����������¥��������������ʮ��̨ͨͿ��ΧάϿ����������Ԫ�����"},
	{"ɡ", "������"},
	{"ɢ", "����װ���������������⻧�����Ǽܼ����ӿ���������ȥ��ɳ��ʧ"},
	{"ɣ", "������Ҷ����"},
	{"ɤ", "������"},
	{"ɥ", "ʧ������������ż��������־��"},
	{"ɧ", "��"},
	{"ɦ", "��ͷ"},
	{"ɧ", "����"},
	{"ɨ", "���赴�ض�����ä����Ĺƽ������β����"},
	{"ɩ", "ɩ��"},
	{"ɪ", "ɪ��"},
	{"ɫ", "����ʱ��ش����ȷ��������äħ����ϵ����������ֽ"},
	{"ɭ", "����"},
	{"ɮ", "������������ͽԺ��"},
	{"ɯ", "ʿ����"},
	{"ɰ", "�����������������ʯ����������ֽ��"},
	{"ɱ", "���е����˷��⺦���۽�¾�������������������ͷ"},
	{"ɲ", "������ʱס"},
	{"ɳ", "���㳡���ض�������Į���������ӻĻʿ�����������©������������ɳʯ��̲��������"},
	{"ɴ", "��������ñ����"},
	{"ɵ", "�ϻ���Ц��"},
	{"ɷ", "�׳�������ס"},
	{"ɸ", "ѡ��"},
	{"ɹ", "���ɺ�̨ͼ"},
	{"ɺ", "��"},
	{"ɻ", "��"},
	{"ɼ", "��ľ"},
	{"ɽ", "����կׯ����ͷ�¹��ȵض������Ըڱ����ˮ��ӳǴ�����������������ž���������´·������ķ������ɫ����ʯ��������ϵ������ҩҰ�������"},
	{"ɾ", "�����ļ���ȥ��"},
	{"ɿ", "���������"},
	{"��", "˸�綯�������ܳ����������ʧ��ҫ��"},
	{"��", "����"},
	{"��", "����������"},
	{"��", "��"},
	{"��", "����ʳ��"},
	{"��", "�������ⱨ����糤�����񷨸���Ӿ�����ʿ����˼����������ս��"},
	{"��", "ͷβ"},
	{"��", "����������"},
	{"��", "д"},
	{"��", "��"},
	{"��", "�Ŀ��˰̺����������Ʋд��纮�ۻ�����������ʹԱ��"},
	{"��", "Ʒҵ��̸��Ǣ�黧������챨����峯�Ǵ��������ӷ����ۺŲ���Ҽֽ����·��ó��Ů����Ȩȶ������������������չսְ����"},
	{"��", "�ͷ������Ǯʶ������"},
	{"��", "��"},
	{"��", "�������Ű���ѧ����Ʒ�߳����������ǰ�˾���±߱����԰��ٲ�˴��δﵱ�۵������˷��÷ط�ڸ湤���ٺûػ𼯼ҽ����ɽֽ������������¥·������Ƭ��ǰȥ����ɽ��������ʿ������˰��̨����ͷ��λξ����������У����ѡѮ������ӳ��Ԫ��������֫װ����"},
	{"��", "���кüѿ�������δ������־"},
	{"��", "ͷ"},
	{"��", "����"},
	{"��", "�Ȳ����͸ߺú���������΢ΪϢСи��������"},
	{"��", "Ѽ�㱭�����ٻ𼦲˵��췹�����ҽ��ᾡ��¼��ƿ��ˮ����"},
	{"��", "ҩ"},
	{"��", "��"},
	{"��", "�ع⻪ɽ��"},
	{"��", "����������׳������Ů�����������ʱ˧˵ξСУ��ү��������"},
	{"��", "������������"},
	{"��", "��ˮ��"},
	{"��", "��"},
	{"��", "�޻�������"},
	{"��", "������Ƿ����"},
	{"��", "������ƤЫ����"},
	{"��", "����̦ͷ��ս"},
	{"��", "���õܵ���������"},
	{"��", "����"},
	{"��", "��Ӱ��ȡȥ������������"},
	{"��", "�̳����񻢻�������Ƶɱ����Դ"},
	{"��", "��"},
	{"��", "��������ˮ����������"},
	{"��", "�ύ���ӽ̱�����������Աַ"},
	{"��", "����"},
	{"��", "�"},
	{"��", "���������������ʩʹ����������"},
	{"��", "��°챨��ǳ�湺��������˵��ԩ"},
	{"��", "��"},
	{"��", "�ֳ����ۼ���������ͷ��ԩչ��"},
	{"��", "����ľӼ۱߼Ҽ���Ӱ�������η���"},
	{"��", "ֱ"},
	{"��", "�����Ѹ߸��ʺ��н�������������������Ϊ��������"},
	{"��", "����������ز���˼����ҹ�⴦�¶ȸи����Ⱥ����������̿���Ũ��ǳ����ɫɽ��ʡ��ˮ̶̸͸Ϊ����ԨԶ��ֿ֪����"},
	{"��", "ʿ"},
	{"��", "���۲ɾ���̬ͨ�������ƶ������ֺ��������ύ������ľũŮ��������Ȩɫʥ˼������̳ͯ����λ����Ч����ѧҽ������ְ־����"},
	{"��", "����"},
	{"��", "��������������˼ƴ������ȸɸ����������УѶ����"},
	{"��", "ĸ������"},
	{"��", "�������û��ô��Ϊ"},
	{"��", "���������"},
	{"��", "����˼����������"},
	{"��", "��©��̼͸"},
	{"��", "����ĸ���������������ƴ�����������������Ƶɫ��������Ϣ����ѧ��Ԯ����"},
	{"��", "�����̬�������Ʋ�Ч������ɳ��涯�ָ�����������ƽ���������·��ĸ��Ƨƽ����ǰȤ������������ΪϢ��Ф����������Ӳ����ֳ������"},
	{"��", "Ů"},
	{"��", "������"},
	{"��", "������ѧ�����¸������ٻ�����ƽǨ������������ֵ��"},
	{"��", "��������"},
	{"ʡ", "��ֱί�����ǵ��õ��ַݸ���Ἦ����������Ǯ����ȥȴʱ������˼��������"},
	{"ʢ", "������俪���緹��ٿ�����ŭ����������˥������װ��"},
	{"ʣ", "��˷���"},
	{"ʤ", "�������ظ�������ȯ��������������"},
	{"ʥ", "�����µص����蹦��ǽ̽ྭ����ĸŮ��ɮˮ̳����ͽ������ѵ��ӡս����ּ��"},
	{"ʦ", "�����������ֱ����д���ܶ���ý�����ĸ��ͽ��ү��Ժ��ר����"},
	{"ʧ", "��ҵȥ������Լ������������߲�쳣��贫�ϴ뵱�ص����ͺ��Ƽ�ڽ����ݿؿ���������������ȴɢɫ������ʵ����������̬��������Ч��ѧѪ����ְ������"},
	{"ʨ", "����"},
	{"ʩ", "�������ŷʸ���չ�ݼӽ̾�������Ϊ��ҩҽ����������"},
	{"ʪ", "�ض�����������"},
	{"ʫ", "�ʸ��輯�㾭�俯ƪ����ʥʷ��̳������ѡѧ����������"},
	{"ʬ", "�Ǽ�����"},
	{"ʭ", "��"},
	{"ʮ", "�����һ�˱��ɴ�񷽸��ѽ������ȫ����������������������"},
	{"ʯ", "��Ӣ�Ҹ�����Ʊ��ڲĵ���շ�Ĺ׻������׾ʿ�����������īŮ��ǽ����ʨ����ͷ����������������"},
	{"ʰ", "�ö޻Ļ�����ȡ��"},
	{"ʱ", "���׼������ۿ�װ�����ٳ����β���ַ��������ھֿտ�����������ȡ������ʱ����̬��������Ч������������ֵ"},
	{"ʲ", "��ô����"},
	{"ʳ", "Ʒ����ָ������ܾ߿�����������ʱ��������������"},
	{"ʴ", "��"},
	{"ʵ", "������ϰ��ҵ�������������д��ﵯ�ظɸл��ݼ��۾ݿ���¼��Ȩȱʩʱ������˵����������Ч��ѧ������սְ֤��"},
	{"ʶ", "��û�����Ȥ������"},
	{"ʷ", "��ٹ۹ݻ������Ǽ���ǰʫʵ��ѧ"},
	{"ʸ", "����־"},
	{"ʹ", "�ó������ùݻ��ھ���Ů��Ȼ����������֮"},
	{"ʺ", "��"},
	{"ʻ", "���ֻؽ�ȥ������"},
	{"ʼ", "���ʾ�ĩ��"},
	{"ʽ", "΢����"},
	{"ʼ", "��"},
	{"ʾ", "������������üž�����"},
	{"ʿ", "���������������"},
	{"��", "���ϴ�ó�����¼ͼμҼ��彻��Ӿֵ�������̬��Ϯϵ������"},
	{"��", "����"},
	{"��", "ʵҵ��������ʱ�˶��󼣼�������ǰȨ����̬������������"},
	{"��", "Ŀȥ"},
	{"��", "�����ݴ�ʦ������ԸԼ"},
	{"��", "ȥ��"},
	{"��", "��ͷ"},
	{"��", "��"},
	{"��", "�ؽ���"},
	{"��", "�ķǷ����˭ν����ָ"},
	{"��", "�þ�˯"},
	{"��", "��Ī��"},
	{"��", "Ӧ�úϲŵ��˶ȿ���������ʱ������ֵ֮��"},
	{"��", "Ů;"},
	{"��", "�ӷ����Ů����"},
	{"��", "�����Ż�����Ȼ����������"},
	{"��", "�ʹ�����"},
	{"��", "��"},
	{"��", "��������ί���渮�������۽�������ߵؾ��������Ķ������ֵ��"},
	{"��", "ǿ����"},
	{"��", "��������"},
	{"��", "�쳪��Ƶ������������ͬͼ����ΪѶҰ��"},
	{"��", "������̽����ͼ�ʾ������������ɹܹ�������̾�������������ӳֽ��װ"},
	{"��", "�ѹ����ػ���ݿ����������¼�س��ɷŷ������߻㼯�ɱ������������£��������������Ǯȡ����ʰ����˰��̯����β��Ϥ��Ч��Ѻ������ִ֧"},
	{"��", "������д����������ָ�����α��ʱ۱����᳭�ֵ綯���и��ȼ��ǽŽ���������ǹ������������ͷ����������������ӡֽ����������"},
	{"��", "��ҳ�쳡������Ҫ�ζ������񷸸����ָ������ҿ�������ö��������������βλϯ��ѡӳ"},
	{"��", "��ҵס���ű��ǵз��ַݹѺ�򻤼ͽ��ھ���ɥʱ��������ҹԼ��"},
	{"��", "����������ɽ˾��������������"},
	{"��", "Ȩ�ۼǽ��侫������ǹ����ͽ��ѫҵ������"},
	{"��", "��̯����������"},
	{"��", "��ƭ�������������ѿ����л��ֳ��ֳ��۹͹������ݼǽ����̽価�����ؿ�����������Ƹ��Ȩ��������ѵ��Ԯ����"},
	{"��", "����������С"},
	{"��", "����Ƥ������ҽ��"},
	{"��", "�˹�"},
	{"��", "��Ŧ��"},
	{"��", "��ͷϴױ��"},
	{"��", "��֪��ʤ��"},
	{"��", "������д"},
	{"��", "�������������Ǯˮ��Ѫ��ҺӮ"},
	{"��", "����������"},
	{"��", "������̹��չ������"},
	{"��", "��Ů��"},
	{"��", "ͨ�������⿣����©��ɢ��Զ"},
	{"��", "�����������д�Ż��������浥�귻���ݹ񺯼мҼܼ�־���������ĿƤ��ǩ������̯ͤ����Ժժիչ����"},
	{"��", "�ؽ������"},
	{"��", "��"},
	{"��", "������"},
	{"��", "������͵ض�������·Ϥ������ʳʶ��˯͸ϰ֪����"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "��ɫ"},
	{"��", "������"},
	{"��", "����"},
	{"��", "��"},
	{"��", "�걲����ҩ����"},
	{"��", "�ضԹ�ʵ��������"},
	{"��", "���ǰʿ��ҵ��"},
	{"��", "����˵ְ"},
	{"��", "����ľҶƤ�µж��ɸ����Թڽ���������������Ӱ֦֭֬��"},
	{"��", "�ִ�������"},
	{"��", "������"},
	{"��", "������"},
	{"��", "��������"},
	{"��", "�־���ѧ��Ŀ�ζ���ȹ��Űٴʿ�������������ǧ��ʮ˵��λϢ����ֵ��"},
	{"��", "��ϴ"},
	{"ˡ", "��"},
	{"ˢ", "�����װ������ϴ��"},
	{"ˣ", "��Ϸ��Ū"},
	{"ˤ", "�򵹵������ǿ�������������"},
	{"˥", "���ܼ���������������΢��"},
	{"˦", "����������"},
	{"˧", "����"},
	{"˨", "��"},
	{"˪", "��������ѩ"},
	{"˫", "ϲ�����ɱ������ܲ㱶������Ŀƴ�Ǵ���ݻɷ��ܹ��ع��żռ����������ǲ����ȫ������ʮ������Ϫ����������ӵ����԰��"},
	{"ˬ", "��ڿ���Լֱ"},
	{"˭", "������Ҳ֪"},
	{"ˮ", "�������ѹ����λ���ֽ����������Ա��ʲ۲ݲ������ذӱõ����Ƶε׶��ʷַݸ׹����ܺ��������⾮��������·½����ī������ţƽƿ����������������Ͱ����ϴϵ����������ӡ��Դ������բ������׼���"},
	{"˯", "������������������ȥʨ��������������"},
	{"˰", "�񵥶�����ο�������ĿƱ��Դ����"},
	{"˱", "��"},
	{"˲", "��ʱϢ"},
	{"˳", "����ˮ���²�δӴ������ͺ�����·����ʱ����λ����������Ӧ������"},
	{"˵", "���������Ѱ׳��ɳ����Ǵʴ������������úͺϽ̿�������ý������������������˵����Ϸ��Ц��"},
	{"˶", "���ʿ"},
	{"˷", "��"},
	{"˹", "������ʱ��"},
	{"˺", "�ɵ��ٿ���Ʊ��ȥ������"},
	{"˻", "����"},
	{"˼", "����Ωά��������·��é��ıĽ�泱������������"},
	{"˽", "�˼�Ӫ�����Ĳش��󷨷����÷ַ߷���������׽�����������������������ͨ������������Թ���������"},
	{"˾", "������������������ͽ��"},
	{"˿", "�������Ϻ���·��������˿����֯����״"},
	{"��", "�������ȵеص�������󻺻���Žǽ���·������ǰ��ȥ������ʬ��ˮ����������Ѷ��Ӳ��ս����"},
	{"��", "Ű����Ӧ"},
	{"��", "��ɮԺ"},
	{"��", "��"},
	{"��", "���ٱڱ߳���¥�溣ͨ�ܴ�����ָ��˹����ϻ��Ἶ���Žǽ�����ƽ��ǧɢ��ʮʱ��������Χά����Ұ������֫��"},
	{"��", "�����"},
	{"��", "�ĵغ�������"},
	{"��", "����"},
	{"��", "�����ذ�ڳ۹��������ڿ���ľ������ɢ������������и֦������"},
	{"��", "������"},
	{"��", "��"},
	{"��", "�Ǵʸ�����"},
	{"��", "�������������ﵽ����������ؼ콻��ú����Ǯ��ȥ����������������ҽ������"},
	{"��", "�峯�ɴʴ�������ƽ��ʷ����"},
	{"��", "������"},
	{"��", "��������"},
	{"��", "������κ�������������Ѱ"},
	{"��", "�ݰı��򵤶����������������������������"},
	{"��", "����������"},
	{"��", "���ƻ�������������������������Ե"},
	{"��", "�ʲĲ˲͵���������ʳ����������������"},
	{"��", "��ɴ�ݶ����ȹ黬�Ǿ���ǢʤʳЧдӡս"},
	{"��", "��"},
	{"��", "�ɽ���������"},
	{"��", "Դ"},
	{"��", "�ἲ����ҵ��ӪԸԹծ��"},
	{"��", "������˵��ԩԸ��״"},
	{"��", "����������Ȼɱ"},
	{"��", "�̲˳��ȸ�������÷ɬ��ʹζ������"},
	{"��", "����ͷ"},
	{"��", "�������˳��÷�������������ʽ��������"},
	{"��", "Ȼ˵��"},
	{"��", "��"},
	{"��", "�������Ե�ݺ󳵴��ӵضӷúͱʻ󼴾�������ʱ����˳��ͬϲ������Ա֮��"},
	{"��", "�Һ��о�Զ"},
	{"��", "������Ƭ��ʯм"},
	{"��", "����ĩĺ������"},
	{"��", "����"},
	{"��", "����Ϫ����Ը"},
	{"��", "����"},
	{"��", "�߶�ŮȨ����ϱ����"},
	{"��", "ʧ�ٺ��Ļ���������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "ʹ"},
	{"��", "�Ա�ɵ�Сдӡ�̷Żؼ�����ˮͷ΢Ӱ"},
	{"��", "����ϸм��"},
	{"��", "�Ե��߼�������ȡȻҪ������"},
	{"��", "�׶����ǹ�ý�������������"},
	{"��", "���м��ڱ䳤�úü���ȡʾ��Ϊν��������֪����˵׫��˵"},
	{"��", "����"},
	{"��", "���������ĶԷ����ҽ�����ɱ��˵������������"},
	{"��", "�ĶԽ�����"},
	{"��", "����"},
	{"��", "��¥"},
	{"̢", "��"},
	{"̤", "ʵ�岽������������ƽ������"},
	{"̥", "λ�����ǽ�ë������"},
	{"̦", "޺"},
	{"̧", "ͷ�����ܸ߼۽ξ�����"},
	{"̨", "�山ɽ����ҳӴʵ��϶����ۺ���������������ǰ����������������������"},
	{"̩", "ɽ���������Ȼ˳������"},
	{"̫", "��"},
	{"̬", "��"},
	{"̫", "ƽ���׹���̫���ִ�๫��"},
	{"̬", "��"},
	{"̫", "�ͺ�����������������������С��ҽ����ԭ������"},
	{"̮", "����"},
	{"̯", "���㷷��������λ��"},
	{"̰", "����ͼ��С�ٱ��ƳԶ�������˯������"},
	{"̱", "����"},
	{"̲", "����ͷͿ"},
	{"̳", "��"},
	{"̴", "��������Խ"},
	{"̵", "��������"},
	{"̶", "����"},
	{"̷", "��ͬ"},
	{"̸", "Ц���嵽�滰��£��������̸��������"},
	{"̹", "�׳ϳе�����Ȼ̹;��"},
	{"̺", "��"},
	{"̻", "��¶��"},
	{"̼", "����ˮ����"},
	{"̽", "������ͷ���ò���鳤���껨�྿����·����ȡʤ����΢��Ϥ��ѯѰ��ԱԴ��֪��"},
	{"̾", "�ʷ���Ϣϧ"},
	{"̿", "�ʻ��𾫾�"},
	{"��", "��ˮ��ҩԲ"},
	{"��", "�ɸ���"},
	{"��", "�ܻʽ���������"},
	{"��", "������ɮɽʫ��ͻ����װ"},
	{"��", "���ֹ�������������ˮҵ��ֽ"},
	{"��", "����Ȼ��ʹδ��"},
	{"��", "��ƽ��������"},
	{"��", "��������ϴ"},
	{"��", "����Ǯ"},
	{"��", "��"},
	{"��", "����"},
	{"��", "�ӻ�����ɫ��԰Դ֥����"},
	{"��", "������ѧ�����ܵ����ݷ��Ļؼҿ�������������ɢ��˰��������ծ"},
	{"��", "�����̭��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "ǱȻ��ұ������"},
	{"��", "�۷����û��۽�Ǯ��������ծ"},
	{"��", "�ͷ�����������ɫ����Ͳͷӡ������סװ��"},
	{"��", "�����ɫ���쿯�Ʋ����Ƴ��˴�Ƚ���Ч�ض����ż���������������������������ǲǿȨ����ʹ��Ϊί����д����ѡ����������Լ��ָ֧������"},
	{"��", "��������"},
	{"��", "Ѷ�Ƴ���ɿ�����Ų��"},
	{"��", "��ʹϧ"},
	{"��", "��¼��дӡ"},
	{"��", "�ζȶӼ�������״��"},
	{"��", "����͸ѡ��"},
	{"��", "�����ſ�����"},
	{"��", "����ʾǰ�߿������Я�������ΰ��ʳ��ɴ��浥���㶽�����ٺ�����������������������ȡ������������Ҫ����"},
	{"��", "Ŀ�ϲĴǴʼǽ���Ϊд����"},
	{"��", "�п�����Ц"},
	{"��", "�����������������±��òʲٲ������������ò������������̬̳ͳ��ίζλ��ϵ������УЭ����������Һ��Ժ"},
	{"��", "������������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����ͷ"},
	{"��", "�����½�Ȼ�����ط�������ʱ���߲ųӳشʹ���ж�ָ����ɹ���������Ӻں�ʻ����ʼ۾�����������������ħ����ţƽ��Ǵǵ��Ȫ����ɫɽ������ʹ����ˮ̨̳����������ͥ����������Ы��������ְ����������"},
	{"��", "����������������"},
	{"��", "��д��������ʿ�����ƽ����Ѽ��д"},
	{"��", "�ݲ��ظ������Ƽ侶��Ķ��������ͷҰ�����"},
	{"��", "��������˵ĵ�Ͼ�����ʳ˯ͷζ����"},
	{"��", "��֪�ܵ���"},
	{"��", "��"},
	{"��", "�β����̴����ƶ����򻨼���ʳˮ��̨����ѡ��ս��"},
	{"��", "����������������������Ŀ��������Լ��"},
	{"��", "��"},
	{"��", "��Ծ�¶���"},
	{"��", "��"},
	{"��", "��۳��������Ž���¥����ǽ��ɡ����ˮ��ԶԽ��ת"},
	{"��", "�߲��ý��Ǯ������ͼϢ����ֽ"},
	{"��", "·֤��˿ʯ������ʱ��������������۸ǹ��չܹ޹��������׼ܽ������������������ĻţƤƬ����������ȭ��ɰˮ��������ͨͰ������мо����"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "����������д���������ڴ����ø�߹�����������ƾ��ȡ����˵Ͳ����Ϸ��������֤��"},
	{"͡", "��"},
	{"ͣ", "ֹҵ����Ź����λ�ְ����ڰ�체�����ٷ���������Ϣ��Ън��ս��ספ"},
	{"ͤ", "̨ͤ��"},
	{"ͥ", "��ǰ��ѵѶ԰Ժ"},
	{"ͦ", "�κý�������������ֱ"},
	{"ͧ", "��"},
	{"ͨ", "֪������Ѷ���������ü���͸˳���ױ𲡲ų����ƴ�������غ��컰����ټ�������������·������Ʊ����������ʷ˵������ͨͳ;�������������������������"},
	{"ͩ", "�س�����"},
	{"ͫ", "������"},
	{"ͬ", "������ʱѧ�������в��Ǵ��������ı�����û�������þ�������·������������������������������̨����ҵһ����Դ־��������٭"},
	{"ͭ", "����Ǯ�����ҳ����Ĺܾ���������ɽ˿��Ԫ"},
	{"ͯ", "�껰�й�����ҥ������װ��"},
	{"Ͱ", "����"},
	{"ͱ", "¦��"},
	{"Ͳ", "��"},
	{"ͳ", "��һ�Ƴ�ս���ηֹ����ܺϽ�����������˧ͳϽ����Ԧ"},
	{"ʹ", "�����޳���������򵿶�����к޻ڻ�����ʧϧ"},
	{"͵", "������"},
	{"ʹ", "��"},
	{"͵", "�����л����տ�������©��������˰͵ϮԽ"},
	{"Ͷ", "�ʻ����߷Ű���������ϵ����еݶ��庯�ϺӼĽ�����Ʊ����������ʯ����ˮ����̥����ӰԵ��ע"},
	{"ͷ", "��ʹ�κ�β������Ƥ�沿���ʳ���ȶ���ݸǹǻ�ҽǽ���������­��Ŀɴ������������������"},
	{"͸", "���ӳ���������������©¶������֧"},
	{"͹", "�������"},
	{"ͺ", "��¿ͷӥ����"},
	{"ͻ", "Ȼ����ط��ɸл�����ΧϮأ"},
	{"ͼ", "����Ƭ�������������������涤�ǽ⾰������ıʽʾ˵����ֽ"},
	{"ͽ", "���ܷѹ�������Ȼ����"},
	{";", "������"},
	{"Ϳ", "�����Ĩѻ"},
	{"��", "���ǵ�����ɱ��"},
	{"��", "�ض�����������˷�Ѹĺ������ҿ���ľ����ǽ��˾������������"},
	{"��", "��¶��̵Ѫެ"},
	{"��", "���Ӵ���"},
	{"��", "����"},
	{"��", "�����ԱԲ�ݲ���ί�ӷѻջ�����У"},
	{"��", "�������ж����ѡ���ǲ⳵�ϳٳ�����������Ϸ����ٿ�������ĥ��ȴ������˵��������Ϊ������ѹ����չ��"},
	{"��", "�ַܱϻ���Ȼɥ������"},
	{"��", "����"},
	{"��", "�仯"},
	{"��", "ɫ"},
	{"��", "�ݻ�ѧ����ͥλ��ɺ󻻻ذܱ��ܲ����������е���������·��ƱǮȥȴ��ɫ����˰��ϯ����ѵ������ְ����"},
	{"��", "�²�����û����ʳ������"},
	{"��", "��������"},
	{"��", "��"},
	{"��", "�߰ѳ��������ſ�������Ƿ��Ь��ҷס��"},
	{"��", "��Ǵʸ����ʹ�������"},
	{"��", "������ˮ����Ь��������������平���ھʿ�֬��äƤƶ��ȥ��������̥������ж"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��������"},
	{"��", "Բ"},
	{"��", "������ΪЭ"},
	{"��", "�Ŀ�����ӡչ"},
	{"��", "��ĭ��Һ"},
	{"��", "�����ص����Ǿ���տ�Ǳȡ����"},
	{"��", "����"},
	{"��", "����ʽ��ЬӾ"},
	{"��", "��"},
	{"��", "����"},
	{"��", "�����޽�������Ƭ˹����"},
	{"��", "����"},
	{"��", "������б"},
	{"��", "������ó�����ʻ㲿ʡ����������ò���������߱������Ʋ�㳡����������������ҹۺŻ������Ӽ侭�����ƿǿܿ�������������ƤƵ������ǽ��������������̲����ͷΧ������������������������Ұ��������Ԯ����ծ��"},
	{"��", "��"},
	{"��", "�ɵ��Ƚ�·��ͷ����"},
	{"��", "ͷ��"},
	{"��", "�߰鷨�������ŪżƱ����ˣζ��Ц������"},
	{"��", "�й̿���Ƥǿʯ֢ͯ"},
	{"��", "����ҩ"},
	{"��", "����ȫ�����ϳ��Ƶ��幤�û������ʤ��˰"},
	{"��", "���������"},
	{"��", "��ؾ���������"},
	{"��", "���Ͱ౨�������㷹�����ڽ�������������������˯ϼ����װ"},
	{"��", "��"},
	{"��", "ϧ"},
	{"��", "Ȼ����ת"},
	{"��", "����˳ϧл��Լת"},
	{"��", "������ȫ���ڷ�Ԫ�������ֶ񸣹Ż��ҽ����¡������ǧ��������������������һ����Դ��״ٹ��"},
	{"��", "����"},
	{"��", "����������"},
	{"��", "�Ʒ��������ڹ����˳��䴢�����Ƹ�������������ç��ĸƼȨ��˷��άλ��үҵ������"},
	{"��", "��ʹ���������"},
	{"��", "����Ȼ��"},
	{"��", "��վַ����ͨ��ҳ���翨�����Ƶ㶵�ιعܼܾ�·��������Ĥ��������ס״��"},
	{"��", "�³�������������ǰ������ʱ��������"},
	{"��", "��ʢ����"},
	{"��", "��Ī��������������"},
	{"��", "���˵��걾����ȴ����"},
	{"��", "������ͼΪ��"},
	{"��", "в���������Ʒ纣������Ȩ��ʢ��������"},
	{"Ρ", "��ȻΡ"},
	{"΢", "��������ЦϸС���۲�ǵ�ַ�������������ĩ������΢����"},
	{"Σ", "���ջ����Ǵ���������¥��ǽ������"},
	{"Τ", "����������"},
	{"Υ", "����Լ�·�����ͽ�������������������"},
	{"Φ", "�Ƹ�"},
	{"Χ", "�Ʊ겶�ǳɶ¹��ۼ߽˽�����£¯������ǽȹס"},
	{"Ψ", "һ�������п�������ʶ"},
	{"Ω", "����һ��"},
	{"Ϊ", "�˺�ֹ����������ƾ��ʱ���˵ĸ�������������������������������˽������ѧҪ������֤֮��׼��"},
	{"Ϋ", "����"},
	{"ά", "�޳ֻ��ͼ�Ħ��Ȩ����ϵ����"},
	{"έ", "����"},
	{"ή", "������"},
	{"ί", "��������Ա������ʵ���������"},
	{"ΰ", "��缨��ҵ��"},
	{"α", "��װ��������֤"},
	{"β", "�Ͳ���������׷"},
	{"γ", "��"},
	{"δ", "��֪���������鰴�������������ɼ���������Ȼ����������׼"},
	{"ε", "��ȻΪ"},
	{"ζ", "������������"},
	{"η", "����������;��"},
	{"θ", "ʹ�װ�����������ҩҺ��"},
	{"ι", "����"},
	{"κ", "������Ρ����"},
	{"λ", "�ñ��ξ���������ͼ����Ԫַ��"},
	{"μ", "��ˮ"},
	{"ν", "��"},
	{"ο", "�ʽ�������"},
	{"��", "����У�����ӹ���������ʿ����"},
	{"��", "����ܰ�Ͷ�ů��Ȫˮϰ"},
	{"��", "������"},
	{"��", "���������ʺ����������������˳����ѱ����"},
	{"��", "����Ӭ�����"},
	{"��", "��������ƾԱ�����ž���ѧ�ձ��ʲŲɲ��������������ﰸ�پ�����㼯����������ä����ɽ��ʥʷ������˼̳����������ѡ��ӡ��Էժ��ְ��������"},
	{"��", "���ﵽ�÷�ۼ�������Ѷ֪"},
	{"��", "��·ü��"},
	{"��", "��"},
	{"��", "�������̽���ѹ��ס׬"},
	{"��", "��"},
	{"��", "���ĺź�𰲰��������������û����������ѯѶնס��"},
	{"��", "��"},
	{"��", "��Դ��"},
	{"��", "������"},
	{"��", "��ţ"},
	{"��", "��"},
	{"��", "�س����ϻ�����ͷ��"},
	{"��", "�ǹ���˵�����ڳ������ȷ��Ҽ����־���ʡ��УԺ"},
	{"��", "��"},
	{"��", "�̲���������ʽ���"},
	{"��", "�ֱ��Ȩȭ��ס"},
	{"��", "����Ұ��"},
	{"��", "��ɽʦ��"},
	{"��", "����"},
	{"��", "˿"},
	{"��", "Ⱦ��ˮ"},
	{"��", "���꺣"},
	{"��", "��"},
	{"��", "�ڼ���������÷��ѻ����������"},
	{"��", "�㹸����������"},
	{"��", "��������"},
	{"��", "���ﶥ��������������������"},
	{"��", "�����޳ܷ��������ܷ������߳����ȱ߲����ӵжȶ˷��칼�ʹֺ����˺λڻ��������ʼ������������������©������������ȤȨ����ɫ��������˫ˮ˽������Ϊζην��������Ͼ����Ча����������������ҵ����������������ԮԵԹ֤֪���������"},
	{"��", "����"},
	{"��", "ͩ��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "����������������"},
	{"��", "����ӹ"},
	{"��", "����ѧ�վ��������ִ�װ���Ϸ�Ըֹ��ٺ󽫽����۵�������ʦʿ����Ϸ����"},
	{"��", "�ʲʽ��һ���ǻ��ٱ�������帣���ȹɹٺ�������ɫʮ̨��������������ָ��"},
	{"��", "����"},
	{"��", "�ͷ����ǰʱ˯����ҹ��"},
	{"��", "̨�����鲽���ض��Ἴ����׿�������ŪŮ��ʨЬ������"},
	{"��", "����"},
	{"��", "������"},
	{"��", "�￴����"},
	{"��", "����̸"},
	{"��", "�ۼ�Ʒҵ�������������ϲ���ɫ��������֤����"},
	{"��", "��"},
	{"��", "����ũ��ʵʹ����"},
	{"��", "������������"},
	{"��", "��ⱨ�Ͳ�ƴ������㹤������ȡɱ��ʱʳ��д��������"},
	{"��", "����ʱ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "װ�ϲͲز���������������ҩҽ�����߲��ǵµ������غ�������������¥������ŷƤ��ɹɽʩʽ������Ͽ����������Ԫ��������"},
	{"��", "�ֹ�ɰ��"},
	{"��", "��Ц"},
	{"��", "�ն�ˮ����������������ȡ����ʪʳ˱Ѫ��ס"},
	{"��", "��������ֽ"},
	{"��", "��"},
	{"ϡ", "��������������ȱ����������������"},
	{"Ϣ", "��ŭǮӰ"},
	{"ϣ", "��������ħ��ͼ��"},
	{"Ϥ", "�������"},
	{"ϥ", "������"},
	{"Ϧ", "����"},
	{"ϧ", "����"},
	{"Ϩ", "�ƻ���"},
	{"Ϫ", "���Ⱥӽ�����ˮͷβ"},
	{"Ϭ", "������ţ"},
	{"ϭ", "��"},
	{"Ϯ", "����ȡ����"},
	{"ϯ", "λ�Ӵεؼ��"},
	{"ϰ", "����������ϰ�����÷�����"},
	{"ϱ", "��"},
	{"ϲ", "����Ѷ����������ƾ翴������ȵ��ɫ��ñ���ӭ������"},
	{"ϳ", "����"},
	{"ϴ", "��������ԡͷ����泾�ӵ���������ȥȾ��ˢ��ѩ���"},
	{"ϵ", "ͳ��������"},
	{"϶", "��"},
	{"Ϸ", "��෨��̨·������Ū��ˣˮ˵��Ժװ����"},
	{"ϸ", "�����Ĳ�쳤�ɷַ컯��ھ���������·ë��Ŀ��������ɳ������˵��΢��ϸ��С������֦������"},
	{"Ϲ", "��³����㻰æ����ץ����"},
	{"Ϻ", "�������"},
	{"ϻ", "ʽ��"},
	{"ϼ", "�ʹ���"},
	{"Ͻ", "�ؾ���"},
	{"Ͽ", "����"},
	{"��", "��Ů��"},
	{"��", "������·С��խ"},
	{"��", "�೵����ڼ����߲��߲㳡ˮ���ʳ��˰Ͱڳ�������︹�����ȵص��������������ŷ繤�򺣻��ؼ��Ҽ޽���ƿ�������������¥������������ȥɽ����������̨����ͬͷ������������ѩѮҰ������֫��ע���"},
	{"��", "��"},
	{"��", "��漾��������������������"},
	{"��", "������������ס��"},
	{"��", "������"},
	{"��", "�������󱲴ﵼ��򸸺ӻ���������������ǰǲ������ʦ������ͷ������������֪��"},
	{"��", "�˲ݵ��ú׼ҽ羳������Ů��̨��ͯ��������"},
	{"��", "�޲˹��컨�����������������ʳζѪ����"},
	{"��", "ά������ϸ��С��"},
	{"��", "�˵�������ʪ����"},
	{"��", "�����޲Ŵ�»�������ʥ����Т"},
	{"��", "�߻��ӽ���"},
	{"��", "��"},
	{"��", "���ĵ��仰��������ɢʱ����̸Ͼְ��"},
	{"��", "Ƥ����"},
	{"��", "������"},
	{"��", "�񷸼���϶����"},
	{"��", "ʾ��΢���������ù�ռ�����¶����Ȼ��ʥ������������ҪҫӰ��"},
	{"��", "���ض�徳����ʤ̲��ЩҪ����"},
	{"��", "����ʵ�������гɳ�������������Ǯ����ʱ����������������ְ״"},
	{"��", "���߳���ʸ������ƽ����������Ѫ��"},
	{"��", "������ί�ݰ�ټ�������ֱ־"},
	{"��", "��"},
	{"��", "Ľ"},
	{"��", "��������"},
	{"��", "��������������"},
	{"��", "�Ʋ����ȶ��������ֹʱ��"},
	{"��", "���ĳ̶�·Ȧ������װ"},
	{"��", "�����׼�������Ȳ����Ƭ����ò�Ƴ˳ִ������ַ·ַ���ɸ����ع��û�����̼Ӽ�����Ͻӽ��۾���������������ȥȰ����������ʶʿ��˼��̸ͨͬͶλ������������Ӧӳӵ��Լ֪��ײ��"},
	{"��", "��"},
	{"��", "����Ƕ��"},
	{"��", "�۽�����ˮ��ζ���Ĳ˲ݲ賦�����۰����뻨�һ𾫿���¯��Ũ��ǮȪ��ɽ����Һ������ֽ������"},
	{"��", "����"},
	{"��", "������������"},
	{"��", "����̶������"},
	{"��", "���°쳤��嵳�ؼ侮������������̸��Ұ������ԭ"},
	{"��", "��ʵ"},
	{"��", "ϸ��̸��ʵ"},
	{"��", "�������"},
	{"��", "�������ӽ⾡������"},
	{"��", "�������������Ҫͨ������������"},
	{"��", "��Ӧ������������"},
	{"��", "�ܸ�������������"},
	{"��", "������ĿȦӢ��"},
	{"��", "����Ū��ս��"},
	{"��", "��ľƤ��"},
	{"��", "��Ƭ��������"},
	{"��", "ǰ���������󱱱�������������������������ѧ����"},
	{"��", "����������������"},
	{"��", "��ǽȻɪɽ�����"},
	{"��", "������"},
	{"��", "��"},
	{"��", "�ɳ��ۼ��ƽ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "Ϣ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "ʧ"},
	{"��", "��"},
	{"��", "�����������׼�ҹ"},
	{"��", "�����ٻ���ټ�·����"},
	{"��", "����źĻٻ����ĥ��ǲ�ڳ�ɢ��������ͣ������ң������"},
	{"��", "��Сҹ"},
	{"��", "�ø�ɫ��"},
	{"С", "��ѧ�麢�Ի��½㳵��ʱ�౦��������˲ݳ��ɳ˳󴬵����ܵ��Ӷ����Ѹ��۹����ù������Ӽƽ��Žڽ��𾶿�����·����è����������ũŮ��Ʒ������������������˯˵ͧ͵��ϪСЬд����ѩ������������վ��ָ׭���������"},
	{"Т", "����������Ů˳�������"},
	{"У", "��԰������೤�����ӶԷ����ٹ滨�ռʼ࿯����������ѵ��ҽ��������ַ׼"},
	{"Ф", "��"},
	{"Х", "��"},
	{"Ц", "������������������ò��̸��������"},
	{"Ч", "�������ʷ�������������Ӧ������"},
	{"Ш", "��"},
	{"Щ", "����΢��"},
	{"Ъ", "�˹�����Ϣ��ҵ"},
	{"Ь", "�Ӱ����ñ����"},
	{"Э", "����ͬ��ӵ������ͻ�����Լ������"},
	{"Ю", "�ִ���ס"},
	{"Я", "�ְ�����ǹ��"},
	{"а", "��ѹ���������·��ħ����˵��"},
	{"б", "�߽�������������������"},
	{"в", "�ƴ���"},
	{"г", "������Ȥ����"},
	{"д", "�ֱ��ɳ����ķ������������ʵ����������������"},
	{"е", "��"},
	{"ж", "��������������ױ"},
	{"з", "��"},
	{"и", "��"},
	{"й", "©¶�ߺ龢����"},
	{"к", "��ҩ"},
	{"л", "л��������Ǻ�������Ļ����"},
	{"н", "��������ˮ��ٺ��"},
	{"о", "Ƭ"},
	{"п", "���"},
	{"��", "��ο��Ȼ����Ϥϲ����"},
	{"��", "�󺥿���������"},
	{"��", "�Ż����ʽ���쳱�ߴ�����ĵ��Ǿɱ�����������۹ɹ⻶���ҽ������ӿ�����·��������Ʒ������������ʫʽ������������������ҩ����ӱ��������ַ֣֪װ����"},
	{"��", "��"},
	{"��", "�����������а�Ѫ����ʹĿ�Ƹʸεذ����鼱���õ����������θ������ݻ��ų��������¾���������������ħ����������������ˮ˼��������̬������ͨͷ��ϸ����������Ҫ��Ը��ս�������"},
	{"��", "��Ϣ���ĺ���������������Ӵ��÷��������̽���ŮƤʵʹ������ͽ����������ֽ"},
	{"��", "�ڹ��ǺӺ��𼶼ʿ�����Ⱥ���ǳ۶���ϵ������ҹ����״����"},
	{"��", "������ζ��"},
	{"��", "����"},
	{"��", "����"},
	{"��", "Ȥ���ܰ����ǵ¸��������¡����ʢ˥����ͷ��ζ��ѧҵ����"},
	{"��", "����ʽ״����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "Ӱ"},
	{"��", "������������������"},
	{"��", "��Ӱֻ"},
	{"��", "��"},
	{"��", "������ò��ɫ��̬��ͬ"},
	{"��", "̨"},
	{"��", "��ҵ��Ϊ�˳������������ߴ̵������ݹ�Ż��߻ἣ�ҽ������������·����ƭ������ɫ����ʡʹʻ������ͷ����������ҽ����ֹװ"},
	{"��", "��Ŀʨ������"},
	{"��", "���˴���ÿ�������δ"},
	{"��", "����������"},
	{"��", "�����ܰ��а�𲡶�"},
	{"��", "ϵ"},
	{"��", "����������������Ȥ��������״��"},
	{"��", "������"},
	{"��", "������ɩ̨"},
	{"��", "���ж񺷺�����ɱ������լ��"},
	{"��", "���󻳿�ǰǻ��͸Χ������������׵"},
	{"��", "ū"},
	{"��", "ӿ"},
	{"��", "����׳��Ա���ŷ�ػƻ뼦������ʦʨΰ����ӥ��"},
	{"��", "��è��"},
	{"��", "Ϣ�����������������Ъѧҵս��ֹ��"},
	{"��", "�������ý���������֤���ִǵ���������������·��Ů��������ʿ��ˮΪϰ��ѧ����������"},
	{"��", "�ѳܷߺ�������ɬ����"},
	{"��", "��ľ"},
	{"��", "����"},
	{"��", "���ŷ�����������ˮ����"},
	{"��", "���¿�����"},
	{"��", "����Ь"},
	{"��", "Ҫ����֪"},
	{"��", "α��ʵ�������ٱ��ʶȸ������Ļû𾪿��տ���������������������������"},
	{"��", "����ů����"},
	{"��", "֪��üҪ��"},
	{"��", "�ݻ�������"},
	{"��", "����Ը��ŵ�������ɾ�"},
	{"��", "ˮ���ı������"},
	{"��", "��"},
	{"��", "������˵̸"},
	{"��", "��"},
	{"��", "����Ļ��������"},
	{"��", "������������"},
	{"��", "��"},
	{"��", "��߶߶��߶"},
	{"��", "����"},
	{"��", "�ഫ���ٽ�ƪƸǩ����Լ"},
	{"��", "��ԯ"},
	{"��", "������������������"},
	{"��", "�����ƳǶ��潲������ʾ��ͳй����սֽ��"},
	{"��", "�°������ҿ�����������"},
	{"��", "�缴��ť����ת��"},
	{"��", "�¹غ���������������������ѧ��ּ��"},
	{"ѡ", "������񵥶��й��úŰαಥ�ĳ��������ο�¼����ƱƸ��ȡ������������������������"},
	{"ѣ", "Ŀ��ҫ��"},
	{"Ѥ", "����"},
	{"ѥ", "��"},
	{"ѧ", "ϰ������У����ҵ����԰��ͽλԺ����Ա���������ɳϵ����ַ縮�ݺúż��ҽ羿��������������������ͯ��ϵ����������ʱʶʿ˵��"},
	{"Ѩ", "����λ"},
	{"ѩ", "�׸⻨��������̳��ܵط���Ƭ��������ɽˮ������ԩԭ"},
	{"Ѫ", "�͹�ѹҺ��ͳԵ���������κۺ켣���������·����������������ɫ��˨ˮ˿��ϴ������ӡ��ծս֬"},
	{"ѫ", "����"},
	{"Ѭ", "����"},
	{"ѭ", "������������"},
	{"Ѯ", "������"},
	{"ѯ", "��"},
	{"Ѱ", "�����˳��������ú�����������˼��ζ������ַ��"},
	{"ѱ", "������˳��"},
	{"Ѳ", "�����Ӱ���������ٺ��ؼ�������ҹ����"},
	{"ѳ", "����������ְ"},
	{"Ѵ", "����"},
	{"ѵ", "����Ǵʵ����������ʾ������"},
	{"Ѷ", "����Ϣ"},
	{"ѷ", "ɫλ"},
	{"Ѹ", "�ټ�������"},
	{"ѹ", "��������ӡե�Ȱ�����ס������ͷ����ɼ۾�����ƽǿ������"},
	{"Ѻ", "�����ָ����Ʊ������ע��"},
	{"ѻ", "Ƭ"},
	{"Ѽ", "����ͷ��"},
	{"Ѿ", "��ͷ��"},
	{"��", "��ǩˢʹ�۸�����ػۼ�ʯҽ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��������ۺŻ�����Ȥ��˼����"},
	{"��", "�ɰ;�����Ȼ��"},
	{"��", "���˵����Ǿ���ŷɪ��̫��"},
	{"��", "��"},
	{"��", "������֪"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��̨ͷ�һ�겨�ݳ��Ѵ��ٶ���ú��Ļ˿Ͳ����ϼҶ�������"},
	{"��", "û��"},
	{"��", "ˮ����ͳǳطֻ�����ɽҵ"},
	{"��", "�����������ط���ʹǴʴ򶬸���������������������ʵ˪����������"},
	{"��", "���ƶ���ĥ����ϰ��"},
	{"��", "���ڲ㶴����ʯм��"},
	{"��", "���������߳�����������ƽ��ʱ������չ�����"},
	{"��", "̸�дǴʽ�������������"},
	{"��", "ɫ������"},
	{"��", "����"},
	{"��", "�ȵۻ���������֢"},
	{"��", "��;���߶���ӽ���·Ϯϰ������"},
	{"��", "��"},
	{"��", "�Ǳβض��ǻ�����û������ӳס"},
	{"��", "ǰ���������ƻ�����Ȧ��ɫ�������ﲿ���׸�����ǽ����������ĿƤ������ͫ����ҩӰ��������"},
	{"��", "����"},
	{"��", "��Ա�೪ʾ�ɳ������������ر䲥˵��ϰϷ������"},
	{"��", "������ɫʷ����������"},
	{"��", "�ӹ�����ɽ����"},
	{"��", "�񷳾���ս"},
	{"��", "̨��"},
	{"��", "��"},
	{"��", "�纯"},
	{"��", "��"},
	{"��", "�����ϯ����"},
	{"��", "��"},
	{"��", "�շ���������ʬ��Ѫ֤"},
	{"��", "������"},
	{"��", "�漰��������"},
	{"��", "������"},
	{"��", "��"},
	{"��", "���ҹ������������÷����"},
	{"��", "���Ա޷�������������"},
	{"��", "����װ"},
	{"��", "ë����ͷ����Ƥ�����Ĥ��Ⱥ������ˮ֬��"},
	{"��", "��¥�����˷����󴬹������Ʋ˲γ�ū����Ǯɡʽ��������������װ��"},
	{"��", "�ⴺ̨������լ���綫�ȹؼ��������ƽȪɡɽ����˷ή����"},
	{"��", "����"},
	{"��", "��Ľɽ�����ͷ����Ӿ��ֹ"},
	{"��", "��"},
	{"��", "��ֳ���ϱ����ϳɴ�ʷַ丸���������·èĸ��Ů����������������"},
	{"��", "�屾������òƷʽ������"},
	{"��", "��蹦����Լ"},
	{"��", "���������Ļ���ʹΧն׵��"},
	{"��", "���־�ħ��а��ұ�"},
	{"��", "��̨��"},
	{"ҡ", "��ͷ�����������ν�����������ҷ"},
	{"Ң", "˴"},
	{"ң", "��Զ��м�����ңף"},
	{"Ҥ", "��"},
	{"ҥ", "����"},
	{"Ҧ", "����ؾ"},
	{"ҧ", "����������ס��"},
	{"ҩ", "ƬƷ�Ĳݳ������������ѷ۸����ƾ�������������ʦˮ����ζ����Ч��ѧҵҺ��������"},
	{"Ҫ", "��в�����������õ��õط����ۺ��ۼ��ǽ����������·ô��Ŀǿ����������������Ю��Ա����ְּ"},
	{"ҫ", "��������"},
	{"Ҭ", "������"},
	{"ҭ", "ס"},
	{"Ү", "·������"},
	{"ү", "��ү"},
	{"Ұ", "������ζ������ݵع��ϻ�����è�˲���ţȮ��ʳʷ��Ѽ��Ӫս��"},
	{"ұ", "����������"},
	{"Ҳ", "�������û�оͿɲ�����Ҫ��������"},
	{"ҳ", "����������"},
	{"ҵ", "�����������羭������"},
	{"Ҷ", "�������ǴԼ�������Ƭ��������"},
	{"Ҹ", "����"},
	{"ҹ", "�����ྰ��У��ͳ����󹤹⺽�������äĻ����ɫ��Ϯ����ݺ"},
	{"Һ", "����̬��ѹ֭"},
	{"һ", "������·�����ֳ��ȱ��ε�Ѷ˰ٰ߰�ﱭ�����೯���δ��������ضȶѶԷ������ָŸɹ���Żλػ�Ｖ�Ҽ��ǽ쾭�پ�ÿ̿ڿ�������������������ö����������������ƬƳ������ǧ����Ⱥ������ɫ����ʮʱ��������˫˲��������ͬͳͷ����ζ������������Щ������������ҹһ��Ա��������չ����ֱֻ������"},
	{"ҽ", "������ѧҩԺsʦ������·���ٻ��������ʿ������������"},
	{"Ҿ", "��"},
	{"��", "����Ȼ�����˴δӴ渽��ɾ�������ϡ��ѭ����Լ��������"},
	{"��", "���˴�������ʼ��"},
	{"��", "�����ܲ��������ڽǽ��������ñȹ������������"},
	{"��", "��԰"},
	{"��", "��"},
	{"��", "������ʧ�鰮�������¹Ǻ��޼�����©����������������������ѵ��Ը��ַ־����������"},
	{"��", "���񲽳�������ֲλ��ת��������ȥ��ɽ����"},
	{"��", "�����������ʽ̬��"},
	{"��", "������Һ��"},
	{"��", "�����Ѱ��㷸�˻��������Ϊ�������"},
	{"��", "�������Ǵ���������������"},
	{"��", "���ĸ����"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "Ѩ����"},
	{"��", "�����ƿ�������������"},
	{"��", "��֪�ʻ�񽫾�Ȼ��������"},
	{"��", "�����Ա���î��Ȳ����ϩ��"},
	{"��", "��ǰ��������Ϊ�ʴ˱���δ�����������������ʾ̫��������"},
	{"��", "������������̳ԱԷչ"},
	{"��", "�ͻ�����ֹ��"},
	{"��", "ѧ�ض��ڶ�����ȼ����ˮλ����"},
	{"��", "��"},
	{"��", "����Ԫ"},
	{"��", "����ʹ"},
	{"��", "�������"},
	{"��", "����Ȥ������"},
	{"��", "ҵ"},
	{"��", "������"},
	{"��", "������򼴼ѿ�Ȼ��"},
	{"��", "˼��ʶ־������ζ�����ᾳ����Ȥ̬ͼν��������������������Ը��ּ"},
	{"��", "��Ȼ"},
	{"��", "�⼰����"},
	{"��", "�����ݵܷ߸������پ�����Ůʦʿ��������ѧ����֫��"},
	{"��", "�洦��������������"},
	{"��", "��������"},
	{"��", "���¶��������̴����ͻ�۾���ϯԱԺ��"},
	{"��", "���ʳɳ��Ե羭����ʦ����Ա������"},
	{"��", "���������ʵ�����˹�������������ͬζ����������"},
	{"��", "����"},
	{"��", "Ϊ���ش˶�������ʽ����ϮѭӦ��Ե֮��"},
	{"��", "�����������ʵ������"},
	{"��", "��������겨������׽�����ƵƷ��ɫ˨��������Ч��Ѷ��������"},
	{"��", "ı������Ӱ�ư����������µ����繦���˺ݻ��꼫�侥������ħ��ƽ��ɭʪ˽��������լ��"},
	{"��", "��Ե"},
	{"��", "��ʫ��ӽ"},
	{"��", "���ưױ��Ҵ����۸����Ӻ�����ƻһ齱����¥Ļ��Ʊ����Ǯɫɽ����ԪԲֽ����"},
	{"��", "����������ý����ҵ�����"},
	{"��", "��î��"},
	{"��", "ʳ����Ʒˮ���赯������������"},
	{"��", "��������·��������öɷ��Ż���Ӿ̾ݿ���������ȼ������ˮ��Ϊ������������֤������"},
	{"��", "����˽�Է������޻伲��û���������������ʿʹ��������������Լ"},
	{"ӡ", "ˢ����������֤���ɳ������Ǽ�ģ��Ⱦ��˳��������"},
	{"Ӣ", "���������˰������ųǳߴ�º�������ܿ�������������ģĶ����ͦ��������"},
	{"ӣ", "������ѩ"},
	{"Ӥ", "����"},
	{"ӥ", "����Ȯ̶"},
	{"Ӧ", "�ø��ó긺������дӴ𵱵öԷ񹩺ͼ��ڽ쾰������ŵƸ����ʱ������������Ϊѡ����������Ԯ����ս����"},
	{"ө", "��Ļ"},
	{"Ӫ", "ҵ�����˲����ضӷ��𽨾���������˽����"},
	{"ӫ", "��Ļ��"},
	{"Ӭ", "ͷ"},
	{"ӭ", "�ӱ����з�Ϻ��������Ȣ����ͷ��ս��"},
	{"Ӯ", "�ü���Ǯȡ����"},
	{"ӯ", "����������"},
	{"Ӱ", "����¥������̳�ڳǵ�����Ƭ��Ȧ��ҵ��ӡԺչ��"},
	{"ӱ", "����"},
	{"Ӳ", "�̱��ԱƳŵ��ȸ�����������ľƴ������ˮ��������"},
	{"ӳ", "������ĳ�������"},
	{"ӵ", "��������������������"},
	{"Ӷ", "��������"},
	{"ӷ", "��"},
	{"Ӹ", "��"},
	{"ӹ", "��µ����"},
	{"Ӻ", "����"},
	{"ӻ", "Ծ"},
	{"ӽ", "̾"},
	{"Ӿ", "�ؽ�̳װ"},
	{"ӿ", "��Ȫ������"},
	{"��", "Զ�ú㰲���𲻲��Ǵ����Ŵ涨���ξ�������"},
	{"��", "������ʿ���ڶὫ��"},
	{"��", "��Ʒ�������������ˮ�������ص����ȷ��ѹ�������ϱ���ƼҾ�����������ú����ȥ����ʱ;��Ϊ������ҩ����������"},
	{"��", "Ĭ���Ȼ���������������������������Թڤ"},
	{"��", "����ݻ�����Խ��������ʤ������Ⱥ�������ԣ��"},
	{"��", "����Ȼ��������Զ"},
	{"��", "�ĳ�߹����������˼���"},
	{"��", "���Ǽ�����Ϊ��"},
	{"��", "������ͷѮ��"},
	{"��", "�ѹ����ֵ���������������ݻ㼯��·����ƱƷͲ����չ��"},
	{"��", "��"},
	{"��", "ԥ�����̫����"},
	{"��", "�����������Ի��Ѳ������ղ�賵���Ʒ��๸�ܹޱñ����ʹ�����Ҽۼ微������·����Ĥī����ƿ��Ȼˮ����ͩͰ��ѹҺӡ����ըֽ֬"},
	{"��", "Ӿ��ˮ��԰�굴�������ǿ�������������˵˿��Ϸ��ѧҽ����������߮"},
	{"��", "��"},
	{"��", "��ЧЩ��־Ե������ʱ�������ز������ɴ����ĵ׵㶾���й�����������������ǮȤȨ��ɫ��ʧ��������Ϊ����������������֪��������"},
	{"��", "�鰮�þ��������Э��"},
	{"��", "�߲෽��������������ȯ���ֱ�������"},
	{"��", "ɫ"},
	{"��", "ƭ�������ж������ջ������ɱ����"},
	{"��", "����ϲ����������ѶҪһ"},
	{"��", "���̾�����ľ��Ů��ʨʱ��ͯСѿ������"},
	{"��", "������"},
	{"��", "������ɳѪ"},
	{"��", "�Ĳ��ʹ�������"},
	{"��", "��Ǯ��"},
	{"��", "����"},
	{"��", "�񱿳մ��۹���³��Ū����ζ��"},
	{"��", "����"},
	{"��", "����Ҧ���������ض��Լ½�����������ȱζϾ������"},
	{"��", "��Խ"},
	{"��", "��Ƭ����������βϺ���������͸׹ǲ���ع������¨����Ⱥ��ҵ��������"},
	{"��", "����"},
	{"��", "�������̰Բ��������۸軧���Ҿ�����������ȨѴҵ��"},
	{"��", "��"},
	{"��", "�ֱ�����"},
	{"��", "ɡ��ˮ�ε����������¶��˿��Ьѩ��"},
	{"��", "��ͬʱ��񹲻�����֮"},
	{"��", "��"},
	{"��", "������"},
	{"��", "���������ʵ����㾳����¼��������˿ϵ��"},
	{"��", "ë�޻�̳��"},
	{"��", "���������������β��ɳص�廷�ʽ���������Ů��ƿȪɽʯ������Ϫ����"},
	{"��", "����"},
	{"��", "�ϻ�����������"},
	{"��", "�Ѵ̵��к��ϼ�������Ϯ��"},
	{"��", "Ϊ"},
	{"��", "�͵к�ǰʷ��ҽ��"},
	{"��", "�ϼ�����"},
	{"��", "�ղ��ܻ���������"},
	{"��", "������"},
	{"��", "Ӥ�ײųɳ����������������"},
	{"��", "������Ϊ"},
	{"ԡ", "����Ѫ���ظ׽���"},
	{"Ԣ", "������������"},
	{"ԣ", "��"},
	{"Ԥ", "������Լ������֧��ѡ�Ƹ��и汨���ⶨ���ֹ���ɽ辯����������ı����������ʾ��ϰ������չ֪����ףװ"},
	{"ԥ", "��"},
	{"ԧ", "����"},
	{"Ԩ", "��Դ޴"},
	{"ԩ", "���Ұ��������������"},
	{"Ԫ", "�����ر���������������������ʼ��˧��ѫ"},
	{"Ԭ", "ö"},
	{"ԭ", "��������������ʼ�汾�������µص㶨���永�ʼ�·òú����������ɫ��ίλ������������Ұ����������ַ֭������װ״�����"},
	{"Ԯ", "�����Ⱦ�������������"},
	{"ԯ", "��"},
	{"԰", "���ض�������������"},
	{"Ա", "��������"},
	{"Բ", "����׶���ɳζ��ٷ���满�����Ѽ���ľ����Ȧ��ɽʯ��ͨͲ��������"},
	{"Գ", "����"},
	{"Դ", "ʼ��Դ������Ȫͷ����"},
	{"Ե", "�ֹ�������"},
	{"Զ", "���߽������Ǹ��ź������̴������ض���������ı����ȥɽ��ʤ��Ͷ������������Զ����־������"},
	{"Ը", "��Ϊ��"},
	{"Թ", "�Ժ޷߸���ŭż��������"},
	{"Ժ", "������������ǽʿ��У��"},
	{"Լ", "�������ָ庲�û�Ƽ���Ī���뵩��̸ͬ��ռ"},
	{"Խ", "��Խ������������ӽ羳������Ȩ����λ����Ұ��"},
	{"Ծ", "����������Ȼ��"},
	{"Կ", "��"},
	{"��", "�ɸ���ĸ����"},
	{"��", "��۾���ʽ���˶�����"},
	{"��", "�������������׷ݹ���������������üĩƱ����ɫʳʴ��̨ͷβϢн��ҹӯԲ����������ٺ"},
	{"��", "��Ŀ"},
	{"��", "������������Ϥ"},
	{"��", "�ϰ���ʲ㵭�˶両�󺣺�����������ĸ����ȸɼɽ������ϼ����ӢӰ������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��ʯ����"},
	{"��", "��ŵ��"},
	{"��", "����ѻ�����������Ӫ�ǳ̳�������ֺ���������������ת"},
	{"��", "�غ�����"},
	{"��", "��"},
	{"��", "��������ѣ��"},
	{"��", "����ĸĿζ��"},
	{"��", "������"},
	{"��", "������������������"},
	{"��", "֧־�ݷѸл��Ʒ���ǼҾӾ�����¼�����ƴ�����ɫʷ��ˣ˵��̸����������������"},
	{"��", "������ֲ�ֵ�"},
	{"��", "���Ѱ���򺦻Ļ�����������"},
	{"��", "��ɱ������"},
	{"��", "�ز�����������������������"},
	{"��", "������˵�ְ治�Ⱥû�����������������ֲ"},
	{"��", "��������У����ְ�����³��������Ҿ�����ǰ��������λ������ѧҰҵ����"},
	{"��", "������"},
	{"��", "Ǯ"},
	{"��", "ʱͣ�𲻴涨��������ȱЪ����ס"},
	{"��", "�����ڳ�������������̾ͬ��"},
	{"��", "�ٿ���"},
	{"��", "������"},
	{"��", "��������"},
	{"��", "�����������������"},
	{"��", "������̣"},
	{"��", "��͵�⴩����ɽ��"},
	{"��", "��"},
	{"��", "��������ׯ��"},
	{"��", "�����������հ��౨�Ͳٲ�����������㷹������������ǰ����˥��Щй������ز"},
	{"��", "����"},
	{"��", "����"},
	{"��", "���ҥֽ�ֲ�ɳ����η��ø����ټ۾�����������Ѫ����"},
	{"��", "��"},
	{"��", "��ʪ"},
	{"��", "�ιֱ��ɳ�򷣼���������"},
	{"��", "��ż��Ҫ��"},
	{"��", "��֮������"},
	{"��", "���ع���"},
	{"��", "�ߴ�������"},
	{"��", "ô�����ĸһ��������"},
	{"��", "ǿ�ӳǴ�ֵ��������������߹�������������ɫɾ����������Ч��ѡѹ��Ԯֳ����"},
	{"��", "���"},
	{"��", "���﹮����Ϊ����������"},
	{"��", "��Ʒ����������"},
	{"��", "��ʵ��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "�ֹ���ƽ������"},
	{"բ", "������"},
	{"գ", "����"},
	{"դ", "����"},
	{"ե", "��ȡ��"},
	{"զ", "��"},
	{"է", "����"},
	{"ը", "�����˳ɳ������ϻ���ҩ"},
	{"թ", "ƭ�۲Ƴƽ�ȡ����"},
	{"ժ", "¼ȡ���೭������Ҫ����"},
	{"ի", "�˷������̽�����������"},
	{"լ", "����"},
	{"խ", "����С"},
	{"ծ", "��Ȩȯ����"},
	{"կ", "��"},
	{"հ", "ǰ�˺�����"},
	{"ձ", "��"},
	{"ճ", "��������Ĥ����Һ��"},
	{"մ", "Ⱦ�߹���ʪˮ��ճ"},
	{"ն", "�ֻ�ɱ����"},
	{"շ", "ת�г���ƽ"},
	{"ո", "¶ͷ����"},
	{"չ", "��ʾ��λ�岥���������¶Ʒ����̨��������ת"},
	{"ջ", "��"},
	{"ռ", "���˲��õؾ�������"},
	{"ս", "���Գ���������ʿ�ذܱ��������ѷ����蹦�Ĺ��������������������ֿ�������Ļ��ǰ����ʤʱʷ����������Ѷ����"},
	{"վ", "�����㶨�Ӹڿ�ǰ̨����ֱס"},
	{"տ", "����Ȼ"},
	{"��", "�ſ���"},
	{"��", "ľ����"},
	{"��", "��̷�����"},
	{"��", "������"},
	{"��", "��"},
	{"��", "�Ҹ��ﲨ��ɹҺ�Ǿ�������������������Ҵ����"},
	{"��", "���չܹ��ʽ̿���Ȩ������ӡ��״"},
	{"��", "��������������ͣ"},
	{"��", "����ĸ��"},
	{"��", "Ŀ��������Ż�����������"},
	{"��", "������������Ŀ"},
	{"��", "����"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��������Ƹ�ܴ���չ������������ɻ꼯����������ļ������ʽ����������ҡ��ԶԹ����"},
	{"��", "���ƽȻʾͨ��ѩ����"},
	{"��", "������ؿ�Ǯ�²��Ѱ"},
	{"��", "����"},
	{"��", "��٢"},
	{"��", "�ೣӦ�������Ƭ�������ȷ����˹ܻ�ɾɿ���������������ʵ˵ҫӳ��׼��"},
	{"��", "������ס��"},
	{"��", "��ͷ����"},
	{"��", "��˻�ʼ������"},
	{"��", "���ؼ��˼���ļ��"},
	{"��", "�����ε��Ϸ�ǹ�����·��������ס"},
	{"��", "ĥ�۾ɿ۰�ɵֵ��϶鷵���ϻ�������������֦����"},
	{"��", "����ѧ"},
	{"��", "����"},
	{"��", "ũ��԰��"},
	{"��", "��ôЩ���ְ�ߴε�ζ����ʻؼҾ���һ����ʱ��������"},
	{"��", "�����"},
	{"��", "ϧ���鰮�����ع�Ʒ������ζϡ"},
	{"��", "����"},
	{"��", "����Ƥ���鳣�ϴ��ĸ��û������پ�������Ʒ������ʵ����˿α��������ֿ֪��������"},
	{"��", "������ѡ"},
	{"��", "��"},
	{"��", "�ٵ½ڽ�"},
	{"��", "��Ͳͷ��֯�����žĿ�âҶձ������"},
	{"��", "����������̽�����Ѷ"},
	{"��", "ͷ���ľ��ϯо"},
	{"��", "��"},
	{"��", "������Ϸ�������"},
	{"��", "����������������������ŭ����Դ��"},
	{"��", "�����ʱ۳ᵴ���ܷ���"},
	{"��", "������ѹʹ��������ƺ��"},
	{"��", "���귨�����ǰ��ʽ��ʹ����Ӫ������"},
	{"��", "����������"},
	{"��", "��Ǯ����"},
	{"��", "���۾�����"},
	{"��", "���Ƹ�ձ����̵��������幺�ܼ���˰;��ѯ����ս����"},
	{"��", "��"},
	{"��", "ȡ��ִ����ǿ����Ȩ��԰������ֳ贴�����˷湺������ʤ��������"},
	{"��", "��"},
	{"��", "���������������װ���൳�ص��ĸ��̺ϻ����������������������ҹ����"},
	{"��", "��"},
	{"��", "��ȷʽ�����˰浱ҵ������Ʒ�������Ȳ��ʹ�����µ�����������긱�������ü���������·��������������ȡ��ɫ��ʷ������������ͳ;λ����������а������Ҫ������ְֱֵ��"},
	{"��", "�߷����α�ٹ��ͼ��ʹ󵳵м��羭�ֿ���������Ȩ������̳��ί��ЭҪ��"},
	{"֡", "Ƶ��"},
	{"֢", "���״"},
	{"֣", "�ݹ�����������"},
	{"֤", "���������մʵ������ȯ��ʵ����"},
	{"֥", "�Ӹ�����"},
	{"֦", "Ҷ�ӽ���ͷ��"},
	{"֧", "�ֲ�Ʊ���Ÿ��ֳ�Ԯ���Ӽ�����ũ��ǰȡʹ��ί��������"},
	{"֨", "��֨"},
	{"֩", "��"},
	{"֪", "��ʶ�������㱾�׷������Ἲ��������������Ȥ����Ϥ����������"},
	{"֫", "����"},
	{"֬", "����"},
	{"֭", "Һ"},
	{"֮", "����һ������������ʼҼ佻������������ǰ����������ʱʼ����˵ͽ������ѧ��������������"},
	{"֯", "Ʒ���ɳ�������Ů����"},
	{"ְ", "��ҵԱλ�����Ƹĸ���Ȩ����˾��У��־��"},
	{"ֱ", "�ӽ�����ͨ���������������ױ�ˬ�������µֺ���������������������˵����ϵϽ������������"},
	{"ֲ", "�����걣����"},
	{"ֳ", "��"},
	{"ִ", "������������ڱʳֵ�������ҵһ������������"},
	{"ֵ", "���Ǯ���մ�ҹ"},
	{"ֶ", "Ů��"},
	{"ָ", "���㶨��ʹ�ػ�ʾ���³Ƴ�������������׼�������ģ��������ͷ��Ϊ����ѹ��ӡժ����֤��"},
	{"ֹ", "��ʹ������ˮϢѪס"},
	{"ֺ", "�������"},
	{"ֻ", "�����µ��ö��˹ܺü�����������������Ҫ����ռ"},
	{"ּ", "��Ȥ����"},
	{"ֽ", "��������汳�Ҵ������л��н���ƬǮͷм��ҵ�����"},
	{"־", "����Ը�ɷ庣��Ȥʿ����"},
	{"ֿ", "��"},
	{"��", "ƿ"},
	{"��", "����"},
	{"��", "л��������"},
	{"��", "���ϴ˴󵱵¶ร�߹���������������������ʥТ�������"},
	{"��", "���������Ǵʵ縻������������Ǹ��ʤʹ����֪"},
	{"��", "�챸����������ҵ�����"},
	{"��", "���ҩֹ�汸�����óɶ��������������ƷʤʽͼӡԼ��"},
	{"��", "��ı�ݹ����������ȡ����Բ��"},
	{"��", "��"},
	{"��", "����Ů��׾����"},
	{"��", "����ص�м������������ѯѺ����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������������"},
	{"��", "���Ʊ���������ü��Ҿ���ƽȨɥɽ����ˮѧ��װ��"},
	{"��", "Ϣ"},
	{"��", "��������������ҽҩ��С��ȼ������ɽѧ�ձ겨���Ͳ�󵯵��ĵ㶫���϶ӷ����Ƿ��ָ���ͼ̼Ὣ����������������ũŷ����������ʽ������������;����У������ѡѮ��ҶӢӹ������ԭ����ָֹ��רת"},
	{"��", "���ĳ��������ʵˡ˳Т������������"},
	{"��", "����¥����ͷ���Ⱞ��ظ"},
	{"��", "��������"},
	{"��", "����վֹ������˹鼫���᾿�þ���������ʼ������"},
	{"��", "�˵��ػ�����ţ��Ⱥ����ֲ��������������"},
	{"��", "������"},
	{"��", "Ҫ���¸��������ε���װ������������쵣������������������ϻ�������������������������ʰ��������Χ������������������ӡ������������������������"},
	{"��", "�ö��鿭����"},
	{"��", "������Ŀŭ˵����ԵԺ"},
	{"��", "��ɽ"},
	{"��", "תĩ����Χȫ���ճ��������������������ʱ�����������������������֪ׯ�"},
	{"��", "���ټʿ�����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����������"},
	{"��", "��"},
	{"��", "������"},
	{"��", "�Ͱ�ü������"},
	{"��", "˹"},
	{"��", "����ҹ"},
	{"��", "��Ȼ��"},
	{"��", "��������������������"},
	{"��", "����"},
	{"��", "˿������"},
	{"��", "����������ɰ��ѧ�����"},
	{"��", "��Ǹν�ƤȦ����ͷѪ���������"},
	{"��", "λ����ǹ������������"},
	{"��", "��"},
	{"��", "�����θ�������¹���ճ�������һ������"},
	{"��", "Ҷ�����˸͹ܼܼ������������¨Ƭ��ɽ��ͲΧ��԰����"},
	{"��", "���"},
	{"��", "���˷�ʳ��"},
	{"��", "Ŀ"},
	{"��", "����"},
	{"��", "Ҫ�ֵ�����۹��⿼��ıҳ���αʱ೪�ΰ�Ӵ�ӷ����帾�ɹ��˺ͻ������������ǽ̿Ϳ�������ƵȨ����ʳʹ��˧������ϯ������������սּ��ץ��"},
	{"��", "��ʵ��������"},
	{"��", "ʯ״��"},
	{"��", "����ѧ�����ʹ�����Ű��ȼ������������"},
	{"��", "����"},
	{"��", "���ش�ˮ��"},
	{"��", "�ɸֹ�������������"},
	{"��", "���ɵ�·��ǽ"},
	{"ס", "լַ�ִ��ط�Ժ�߻���������������"},
	{"ע", "������Ŀ���Ž�������ɫ��������������"},
	{"ף", "���Ǵʵ��ؾ�����Ը"},
	{"פ", "�ط��ۻ���������������������"},
	{"ץ", "ס�����ĺû��������ȡȥͼϹ��"},
	{"צ", "����"},
	{"ר", "����ҵ�����������������ⰸһ�������̳ϵ�Ϸ��ø幥���ܹ񺯺ź������������Ȩ����������������ӪԱ����ְ������ע��"},
	{"ש", "������ǽͷ��"},
	{"ת", "�ø�ѧ����ҵ�����ۻ������ֱ䲥���ɳг��ﵽ��������������ػ���޽��ǽӽ����¯¼����Ȧ��������˲������ͷ����Ϊ��������������ս����ְ���"},
	{"׫", "������д��"},
	{"׬", "��Ǯȡ"},
	{"׭", "������"},
	{"ׯ", "���Ҽڼ���԰�����Ӻ�"},
	{"װ", "�޻���ж�����α����ز����ɳ����������޺ü׽�������ɵ��������Ϊ��������֡�����������"},
	{"ױ", "���"},
	{"ײ", "�˽����Ƴ���������������������"},
	{"׳", "ʿ־�������嶡�۽�����������ʵ˶"},
	{"״", "���̬��Ԫֽ��"},
	{"׵", "��"},
	{"׶", "����"},
	{"׷", "�����沶��򵽵��ʸϹ����ػڻ����Ǽӽɽ˾�����ɱ������˼��������β����Ѱ������ײ"},
	{"׸", "������"},
	{"׹", "�ػٻ�¥������"},
	{"׼", "ʱ��ȷ���ȶ�����ͷ��������"},
	{"׽", "סŪ����������"},
	{"׾", "����������"},
	{"��", "������"},
	{"׿", "����Ⱥ������ȻʶϪ��Խ��"},
	{"��", "���Ž���"},
	{"��", "ĥ"},
	{"��", "׳"},
	{"��", "��������"},
	{"��", "ľ��ʳ"},
	{"��", "�����۱ʻ�����½����ħɫʵ����װ"},
	{"��", "������"},
	{"��", "��ˮ��"},
	{"��", "��"},
	{"��", "��ѯ"},
	{"��", "�����������Դ�ĲƷ�����Ѷ������"},
	{"��", "ɫ��̬Ӱ"},
	{"��", "������������ζ����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ɫ�˹����ޱ��������"},
	{"��", "ϸ"},
	{"��", "Ů������������漯����·��ĸĿ��ʱ������ҶҹԻ"},
	{"��", "��Ȼ�����ض������������˽���������Ѱ��ΰװ챣���Ʊ��ձ�в�ֳﴦ�����˴Ӵ�����ٷ⸺�������Ҽ콨�����ȾӾ������ؿ�������������Űǿȡȼ����ɱʡ����������ο����ϰ������������ѡѧӪ��������Ը����֪����������ڼ��"},
	{"��", "���ĸ������η����Ż������ھݾ������ģĻ����������������������Ԫֽ"},
	{"��", "ɫ���"},
	{"��", "��Ӱ"},
	{"��", "�̱�����������ʥʦ��ּ�����"},
	{"��", "����������"},
	{"��", "���ܽ��������ͳ����β������Ƴɴǵõ�ָٹ�������ͺ�����Ƽۼ����������������������̨��ͼ����Ҫ����վ����ֵ֧֮װ"},
	{"��", "�鲽�ӹ۹���������Ȼ������ʹ̸����"},
	{"��", "�һ�"},
	{"��", "·��˽��������ʧ��ɢ���������ܱ鳪�������������ù����ػ���©��ȥ��������̨ζ����"},
	{"��", "��������Ч"},
	{"��", "�����ݷѻ���������˰����Լ"},
	{"��", "���������ʵ׶������������̳��Э����ӡ��"},
	{"��", "��"},
	{"��", "������Ⱥ����"},
	{"��", "���������ظ�����ĸ��ʦ����ҵ��"},
	{"��", "��"},
	{"��", "ֹ�����϶������ؾ���������������"},
	{"��", "��֯�𳤳ɴʸ��������ʫͷͼ��ѵԱװ"},
	{"��", "ʯ�гɶ���������տ���̽Ӫ��"},
	{"��", "��"},
	{"��", "�Ͳ���������Ӳ"},
	{"��", "�Ʋ赹������������������"},
	{"��", "��ú󻵰����ٳ������տ��߶̼ѽ�����������Ϊ��С��������"},
	{"��", "�й�������������������֤״��"},
	{"��", "��ʦ���Ƴ�󾴿�����Ϊ������"},
	{"��", "�ذ�ӷ������ѭ����"},
	{"��", "������ҹ"},
	{"��", "��˼�߰��۲ഫ���������Ž���������Ȩ������Ӫ��ת"},
	{"��", "������֤"},
	{"��", "������������Ϸ�����ٳɳ����𵽶��������ٹ���ٿ���ý��������ΪЩ��ׯ"},
	{"��", "����Ʒҵ����Ϊ�����ķ�Զ񰸰ձ��ױ�ٳɴ𵽶������Ϲ����Źֺû��ټۼ޿�������������ŪŻ����ʫ����̬ͼ��Ϣ��ЩЭ��ս֤��ׯ"},
	{"��", "λ��ԡ�굽�ȵ滯����������̨����ׯ��"},
	{"��", "�공��κŻ���̸λ��������"},
	{"أ", "��"},
	{"ا", "��"},
	{"ب", "��"},
	{"ة", "��"},
	{"ج", "������"},
	{"ذ", "��"},
	{"ز", "����"},
	{"ع", "��"},
	{"غ", "��"},
	{"ؽ", "������"},
	{"ؿ", "ˮ"},
	{"��", "��"},
	{"��", "��ɱ��"},
	{"��", "Ʒ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��֮��"},
	{"��", "��"},
	{"��", "�ⲹ��"},
	{"��", "����"},
	{"��", "Ч"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ٳ"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��ʧ"},
	{"��", "��"},
	{"٤", "����"},
	{"٩", "��ɽ٩"},
	{"٪", "��"},
	{"ٮ", "ٮ��"},
	{"ٲ", "Ȼ"},
	{"ٳ", "��Ӱ"},
	{"ٵ", "����"},
	{"ٹ", "��֮��"},
	{"ٺ", "��"},
	{"ٻ", "Ӱ"},
	{"ټ", "��"},
	{"ٽ", "��"},
	{"ٿ", "�ض���Ȼ"},
	{"��", "��"},
	{"��", "��ʹ"},
	{"��", "��"},
	{"��", "ʦ��"},
	{"��", "ͬ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "Խ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��ҹ��Ը"},
	{"��", "��"},
	{"��", "��"},
	{"��", "���и���"},
	{"ڤ", "��������"},
	{"ڨ", "Ц"},
	{"ک", "��"},
	{"ګ", "��"},
	{"ڮ", "��"},
	{"گ", "��"},
	{"ڲ", "ƭ"},
	{"ڴ", "��"},
	{"ڵ", "������"},
	{"ڶ", "г"},
	{"ڸ", "��"},
	{"ڹ", "��ע"},
	{"ں", "����"},
	{"ڻ", "����"},
	{"ھ", "��"},
	{"ڿ", "ƭ��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ʾּ"},
	{"��", "��"},
	{"��", "��ѯ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "İ"},
	{"��", "��"},
	{"ۤ", "��"},
	{"ۯ", "��"},
	{"۰", "��"},
	{"۳", "��"},
	{"۶", "����"},
	{"ۻ", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"ܰ", "��"},
	{"ܽ", "��"},
	{"ܾ", "ݴ"},
	{"ܿ", "ܿ"},
	{"��", "��"},
	{"��", "ޣ"},
	{"��", "������"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"ݡ", "��"},
	{"ݩ", "��"},
	{"ݫ", "����"},
	{"ݬ", "��"},
	{"ݰ", "��"},
	{"ݱ", "����"},
	{"ݷ", "ݷѧ��"},
	{"ݸ", "��"},
	{"ݺ", "��"},
	{"ݼ", "��"},
	{"��", "��"},
	{"��", "˿��"},
	{"��", "ȡ"},
	{"��", "��Ȼ"},
	{"��", "��"},
	{"��", "޼"},
	{"��", "����"},
	{"ޥ", "��"},
	{"ާ", "��"},
	{"ެ", "����"},
	{"޹", "Ⱦ��"},
	{"޺", "̦"},
	{"޻", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ע"},
	{"��", "��"},
	{"��", "��֮��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "����"},
	{"ߢ", "ȡ"},
	{"ߦ", "����"},
	{"ߪ", "������"},
	{"߱", "����ĸ"},
	{"߳", "����"},
	{"ߴ", "��"},
	{"ߵ", "�ݻ�����ͷл"},
	{"߶", "����"},
	{"ߺ", "��"},
	{"߽", "��"},
	{"��", "ߴ���"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�ͱ���"},
	{"��", "�"},
	{"��", "����"},
	{"��", "ߴ"},
	{"��", "߶"},
	{"��", "��"},
	{"��", "�ú�ʶ��֪"},
	{"��", "��"},
	{"��", "��"},
	{"�", "����"},
	{"�", "Ѫ"},
	{"�", "�"},
	{"�", "��"},
	{"�", "Ȼ��̾"},
	{"�", "�"},
	{"�", "��֮ʳ"},
	{"�", "��"},
	{"�", "���"},
	{"��", "��"},
	{"��", "ѽ"},
	{"��", "Ц"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�"},
	{"��", "��"},
	{"��", "ͨ����"},
	{"��", "������"},
	{"��", "ͷ"},
	{"��", "��ž��ž"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"�", "Ļ��"},
	{"�", "Ȼ"},
	{"�", "᧿�Σ"},
	{"�", "��"},
	{"�", "��"},
	{"�", "����"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"��", "ɽ"},
	{"��", "�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ɽ��"},
	{"��", "�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��˽"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"�", "��"},
	{"�", "������Ȼ"},
	{"�", "����"},
	{"�", "����"},
	{"�", "ͷ��Ŀ"},
	{"�", "��"},
	{"�", "Ե"},
	{"��", "��"},
	{"��", "�"},
	{"��", "��"},
	{"��", "Ʒ��ѡ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "Ȼ�"},
	{"��", "��"},
	{"��", "���"},
	{"��", "Ŀ����Ȼ"},
	{"��", "Ȼ��"},
	{"��", "��"},
	{"��", "��Ȼ��"},
	{"��", "Ȼ"},
	{"��", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��̰"},
	{"�", "��"},
	{"�", "�"},
	{"�", "��"},
	{"�", "Ȼ"},
	{"�", "Ȼ��"},
	{"�", "ɫ"},
	{"�", "Ȼ��"},
	{"�", "ͷ��ס"},
	{"�", "㷲���"},
	{"�", "��"},
	{"�", "�"},
	{"�", "�"},
	{"��", "��"},
	{"��", "����"},
	{"��", "ֵ"},
	{"��", "ǽ"},
	{"��", "������"},
	{"��", "��ʧ"},
	{"��", "����"},
	{"��", "��"},
	{"��", "�����ԡ"},
	{"��", "��"},
	{"��", "�һ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "Ϫ"},
	{"��", "û��"},
	{"��", "��μ"},
	{"�", "������"},
	{"�", "��"},
	{"�", "�"},
	{"�", "��"},
	{"��", "��"},
	{"��", "ְ"},
	{"��", "¹��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "û��"},
	{"��", "��"},
	{"��", "ѩ"},
	{"��", "Ⱦ"},
	{"��", "Ȼ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"�", "��̨"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "ˡ"},
	{"�", "��"},
	{"�", "����"},
	{"��", "Ȼ��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��ͥ����"},
	{"��", "ң"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��������˼����"},
	{"��", "��"},
	{"��", "ѡ"},
	{"��", "��Ȼ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ˮ"},
	{"��", "��"},
	{"��", "��"},
	{"�", "�����"},
	{"�", "��"},
	{"�", "�"},
	{"�", "�"},
	{"�", "ͯ"},
	{"�", "����"},
	{"�", "�򸾾�ͷ"},
	{"�", "���̺�"},
	{"�", "������"},
	{"�", "��"},
	{"�", "�"},
	{"�", "��"},
	{"�", "��"},
	{"�", "�����"},
	{"�", "Ů"},
	{"�", "��"},
	{"��", "�ͺ�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�˿��"},
	{"��", "��"},
	{"��", "��ˣˮϷЦ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����׷"},
	{"��", "��"},
	{"��", "��վ"},
	{"��", "����"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��ӵ�"},
	{"�", "©"},
	{"�", "��"},
	{"�", "��"},
	{"�", "�̼���"},
	{"�", "������"},
	{"�", "����"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�"},
	{"��", "˿"},
	{"��", "����"},
	{"��", "��"},
	{"��", "�"},
	{"��", "��������"},
	{"��", "����"},
	{"��", "����"},
	{"��", "�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"�", "٤��"},
	{"�", "����褴�"},
	{"�", "��"},
	{"�", "��"},
	{"�", "�"},
	{"�", "��"},
	{"�", "������"},
	{"�", "�����"},
	{"�", "������"},
	{"��", "��"},
	{"��", "Ȼ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "������"},
	{"��", "ľ��"},
	{"��", "�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����ľ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�ٸԸ�������"},
	{"��", "�"},
	{"�", "��"},
	{"�", "��"},
	{"�", "ç"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "�"},
	{"��", "ɫ����"},
	{"��", "������ʯ"},
	{"��", "������"},
	{"��", "������"},
	{"��", "�"},
	{"��", "����"},
	{"�", "ѧ"},
	{"�", "��"},
	{"�", "��"},
	{"�", "Ȼ"},
	{"�", "��"},
	{"�", "�"},
	{"�", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "������Ц"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ţ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"�", "��"},
	{"�", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "֬"},
	{"��", "���˿�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"�", "ѪΪ��"},
	{"�", "Ȼˬ"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��Ȼ"},
	{"�", "��"},
	{"�", "�"},
	{"��", "��"},
	{"��", "Ŀҫ"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ҳ"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�Ƕ�������Ȥɮʦ����ζѧ����Ժ��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "Ϣ"},
	{"��", "��"},
	{"��", "ɽ"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"�", "��"},
	{"�", "����"},
	{"�", "Υ"},
	{"�", "˯"},
	{"�", "Ŀ"},
	{"�", "Ŀ"},
	{"�", "��"},
	{"�", "��"},
	{"�", "������Ѻ"},
	{"��", "ϴ"},
	{"��", "��"},
	{"��", "������"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "������"},
	{"��", "���ؽ�"},
	{"��", "������"},
	{"��", "�̿�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ʸ"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "������"},
	{"��", "��"},
	{"��", "��ɽ"},
	{"��", "��"},
	{"�", "�����Ͻ���Ĥ������Һס"},
	{"�", "��"},
	{"�", "��"},
	{"�", "���"},
	{"�", "�������"},
	{"�", "��"},
	{"�", "�ϼ�"},
	{"�", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�°ٽ�"},
	{"��", "��"},
	{"��", "�"},
	{"��", "������"},
	{"��", "�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "֢"},
	{"��", "�ӷ�"},
	{"��", "��"},
	{"��", "��Ѫ"},
	{"��", "��"},
	{"�", "��"},
	{"�", "���"},
	{"�", "����"},
	{"�", "����"},
	{"�", "��¡"},
	{"�", "�"},
	{"�", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ķ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�ֹ���"},
	{"��", "��"},
	{"��", "����Ѷ"},
	{"��", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "��"},
	{"�", "ü��"},
	{"�", "�Ͼ���"},
	{"��", "��"},
	{"��", "�"},
	{"��", "��"},
	{"��", "¥����"},
	{"��", "�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��������"},
	{"��", "��"},
	{"��", "������"},
	{"��", "��"},
	{"��", "�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"�", "з"},
	{"�", "�۵�����"},
	{"�", "�"},
	{"�", "��"},
	{"�", "����"},
	{"�", "���۹���"},
	{"�", "��"},
	{"��", "������"},
	{"��", "϶"},
	{"��", "������ʵ����ѧ־"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "·����"},
	{"��", "ϯ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��ĥ"},
	{"��", "��"},
	{"��", "ƽ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "Ȼ����"},
	{"��", "Ȼ��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ü"},
	{"��", "��"},
	{"��", "ͻȪ"},
	{"��", "����"},
	{"��", "�ΰ�"},
	{"��", "��"},
	{"��", "��"},
	{"��", "���緢"},
	{"��", "��"},
	{"��", "�����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "�������"},
	{"��", "��"},
	{"��", "��"},
	{"��", "Ƥ���"},
	{"��", "�ｻ��"},
	{"��", "��"},
	{"��", "Ů����"},
	{"��", "��"},
	{"��", "ʱ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "���"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "ͷ"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "¹"},
	{"��", "��"},
	{"��", "ս"},
	{"��", "��"},
	{"��", "��"},
	{"��", "����"},
	{"��", "��"},
	{"��", "��"},
	{"��", "��Ȼ"},
	{"��", "��"}
};

*/

/*����ָ����в���༭*/
/*���������������abc  ��ABC  ���뷨��*/
static void my_AccordPointInsertEdit (const u8 *TheFirstAddrOfBuff, const u8 *pMove, char StartLine, char EndLine, u8 *cursorx, u8 *cursory)
{
	u8 totalline;	//�༭���м���
	int bytenum;	//��buff  ͷ����괦�ж��ٸ��ַ�
	u8 byteline;	//��buff  ͷ����괦��Ҫ���ٸ�����ʾ
	//int bytetotal;	//buff  �ܹ��ж��ٸ��ַ�
	u8 i, j;
	const u8 *display;
	char disp[23];

	*cursorx = 0;
	*cursory = 0;

	totalline = EndLine - StartLine + 1;
	bytenum = pMove - TheFirstAddrOfBuff;
	//bytetotal=strlen(TheFirstAddrOfBuff);

	byteline = bytenum / ALineNum;

	if (bytenum % ALineNum) byteline++;

	display = TheFirstAddrOfBuff;	//�ҳ���Ҫ��ʾ�ĵ�ַ

	if (byteline > totalline)
	{
		for (i = 0; i < byteline - totalline; i++)
		{
			for (j = 0; j < ALineNum; j++, display++)
			{
				if (*display > 0x80)
				{
					display++;
					j++;
				}
			}
		}
	}

#ifdef DEBUG_PRINTF
	printf ("display=%s\n", display);
#endif

	if (*display != 0)  		//������ַ�
	{
		for (i = 0; i < totalline; i++)  			//��ʾpMove  ֮ǰ֮������" ��ʾ��Χ֮��"  ���ַ�
		{
			for (j = 0; j < ALineNum && *display != 0;)
			{
				if (*display > 0x80)
				{
					disp[j] = *display;
					j++;
					display++;

					if (display == pMove)
					{
						*cursory = i;
						*cursorx = j;
					}
				}

				disp[j] = *display;
				j++;
				display++;

				if (display == pMove)
				{
					*cursory = i;
					*cursorx = j;
				}
			}

			for (; j < ALineNum + 2; j++) disp[j] = ' ';			//�˴�ALineNum+1  Ϊ��ȥ��ɾ���ַ��ǣ���������ʾ������ֵ�����

			disp[j] = 0;
#ifdef DEBUG_PRINTF
			printf ("disline=%s\n", disp);
#endif
			text_out_to_row_Language2 ( (unsigned char) StartLine + i, (unsigned char*) disp, (unsigned char*) disp);
		}
	}
	else 		//���û�ַ������п�����ɾ�����ˣ�����Ļ��ʣһ���ַ�
	{
		text_out_to_row_Language2 ( (unsigned char) StartLine, "   ", "   ");
	}

#ifdef DEBUG_PRINTF
	printf ("bytenum=%d\n", bytenum);
#endif

	*cursorx *= 6;
	*cursory += StartLine;
	*cursory *= 13;
	flashcursor (*cursorx, *cursory);
}


static void DisplayContaiPYHaizi (char PYrowcnt, const T9PY_IDX **pT9PY, char *PYbuff, char addid, char pagecnt, char *HaiziRightShiftmax)
{
	int x, i;
	char tb[25];
	const char *pMB;
	char pybuf[8];
	const u8 NumData[10][5] =  		//�����ߣ����أ�: 4��5 ����ȡģ���ֽڵ���
	{
		{0x1F,0x11,0x1F,0x00},	//_0
		{0x00,0x1F,0x00,0x00},	//_1
		{0x1D,0x15,0x17,0x00},	//_2
		{0x15,0x15,0x1F,0x00},	//-3	
		{0x07,0x04,0x1F,0x00},	//-4
		{0x17,0x15,0x1D,0x00},	//_5
		{0x1F,0x15,0x1D,0x00},	//_6
		{0x01,0x01,0x1F,0x00},	//_7
		{0x1F,0x15,0x1F,0x00},	//_8
		{0x17,0x15,0x1F,0x00}	//_9
	};

	pMB = PYbuff;

	for (i = 1; i < PYrowcnt;)
	{
		if (*pMB == ' ') i++;

		pMB++;
	}

	memset (pybuf, 0, sizeof (pybuf) );

	for (i = 0; i < 8 && *pMB > ' '; i++, pMB++)
	{
		pybuf[i] = *pMB;
	}

#ifdef DEBUG_PRINTF
	printf ("pybuf=%s\n", pybuf);
#endif

	for (i = 0; t9PY_index[i].T9 != NULL; i++)
	{
		if (strcmp ( (char*) t9PY_index[i].PY, pybuf) == 0)
		{
			break;
		}
	}

	if (t9PY_index[i].T9 != NULL)
	{
#ifdef DEBUG_PRINTF
		printf ("t9PY_index[i].MB!=NULL\n");
#endif
		*pT9PY = &t9PY_index[i];
		pMB = (const char*) t9PY_index[i].MB;
		pMB += pagecnt * 14;
#ifdef DEBUG_PRINTF
		printf ("pMB=%s\n", pMB);
#endif

		if (strlen (pMB) / 2 / 7 > 0) *HaiziRightShiftmax = 6;
		else *HaiziRightShiftmax = strlen (pMB) / 2 % 7 - 1;

		memset (tb, 0, sizeof (tb) );

		for (i = 0; *pMB != 0;)
		{
			tb[i] = ' ';
			i++;
			tb[i] = *pMB;
			i++;
			pMB++;
			tb[i] = *pMB;
			i++;
			pMB++;

			if (i > 20) break;
		}

		clear_area_to_row (MaxRowOneScr - 1, MaxRowOneScr - 1);
		text_out_to_row_Language2 (MaxRowOneScr - 1, (unsigned char*) tb, (unsigned char*) tb);
		if (addid)  			//��ÿ�����ּ���1234567  ���
		{
			for (x = 0, i = 0; i < 20; i++)
			{
				if (tb[i] == 0) break;

				if (tb[i] == ' ')
				{
					draw_pic (NumData[x + 1], x * 18 + 2, 53, 4, 5);
					x++;
				}
			}
		}

		reverse_area_to_row (6, MaxRowOneScr - 1, 12, 14);
		draw_line_to_row (MaxRowOneScr - 2);
	}
}

static void DisplayBH (const char *key09)
{
	const char *pMB;
	char x;
	const u8 heng[6] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x00};
	const u8 shu[6] = {0x00, 0x00, 0xFC, 0x00, 0x00, 0x00};
	const u8 pie[6] = {0x04, 0x08, 0x10, 0x20, 0xC0, 0x00};
	const u8 na[6] = {0xC0, 0x20, 0x10, 0x08, 0x04, 0x00};
	const u8 zhe[6] = {0x80, 0x80, 0x80, 0x84, 0xFC, 0x00};

	pMB = key09;	//�ڵ����ڶ�����ʾ�ʻ�

	for (x = 0; *pMB != '\0'; x += 6, pMB++)
	{
		if (*pMB == '2')		draw_pic (heng, x, 44, 6, 6);
		else if (*pMB == '3')	draw_pic (shu, x, 44, 6, 6);
		else if (*pMB == '4')	draw_pic (pie, x, 44, 6, 6);
		else if (*pMB == '5')	draw_pic (na, x, 44, 6, 6);
		else if (*pMB == '6')	draw_pic (zhe, x, 44, 6, 6);
	}
}
static void DisplayContaiBHHaizi (const T9BH_IDX **pT9BH, char *key09, char addid, char pagecnt, char *HaiziRightShiftmax)
{
	int x, i;
	char tb[25];
	const char *pMB;
	const u8 NumData[10][5] =  		//�����ߣ����أ�: 4��5
	{
		{0xF8, 0x88, 0xF8, 0x00},	//_0
		{0x00, 0xF8, 0x00, 0x00},	//_1
		{0xB8, 0xA8, 0xE8, 0x00},	//_2
		{0xA8, 0xA8, 0xF8, 0x00},		//3	//_3
		{0xE0, 0x20, 0xF8, 0x00},		//4	//_4
		{0xE8, 0xA8, 0xB8, 0x00},	//_5
		{0xF8, 0xA8, 0xB8, 0x00},	//_6
		{0x80, 0x80, 0xF8, 0x00},	//_7
		{0xF8, 0xA8, 0xF8, 0x00},	//_8
		{0xE8, 0xA8, 0xF8, 0x00}	//_9
	};

	DisplayBH (key09);	//�˴���key09  ������pT9BH  ����Ϊ��"662446"  ������ϣ��ʻ���ʾ�������⡣

	pMB = (const char*) (*pT9BH)->MB;
	pMB += pagecnt * 14;
#ifdef DEBUG_PRINTF
	printf ("pMB=%s\n", pMB);
#endif

	if (strlen (pMB) / 2 / 7 > 0) *HaiziRightShiftmax = 6;
	else *HaiziRightShiftmax = strlen (pMB) / 2 % 7 - 1;

	memset (tb, 0, sizeof (tb) );

	for (i = 0; *pMB != 0;)
	{
		tb[i] = ' ';
		i++;
		tb[i] = *pMB;
		i++;
		pMB++;
		tb[i] = *pMB;
		i++;
		pMB++;

		if (i > 20) break;
	}

	clear_area_to_row (MaxRowOneScr - 1, MaxRowOneScr - 1);
	text_out_to_row_Language2 (MaxRowOneScr - 1, (unsigned char*) tb, NULL);

	if (addid)  		//��ÿ�����ּ���1234567  ���
	{
		for (x = 0, i = 0; i < 20; i++)
		{
			if (tb[i] == 0) break;

			if (tb[i] == ' ')
			{
				draw_pic (NumData[x + 1], x * 18 + 2, 53, 4, 5);
				x++;
			}
		}
	}

	reverse_area_to_row (6, MaxRowOneScr - 1, 12, 14);
	draw_line_to_row (MaxRowOneScr - 2);
}


static void HighLightPY (const char *buff, char newpy)
{
	const char *buffStart, *buffPY;
	char diplaybuff[22];
	u8 i, j, zifunum;
	char temp, xpos = 0;
	char sjxflag = 0;	//�����Ƶ������α�־
	const char leftsjx[] = {0x10, 0x38, 0x7C, 0xFE, 0x00};
	const char rightsjx[] = {0xFE, 0x7C, 0x38, 0x10, 0x00};

	buffPY = buff;	//������ж��ٸ�ƴ���������:  "piao pian qian qiao shan shao "  ��ôzifunum=4��
	zifunum = 0;

	while (*buffPY != ' ')
	{
		zifunum++;
		buffPY++;
	}

	buffPY = buff;	//�ҳ�Ҫ��ʾƴ����λ�á�

	for (i = 1; i < newpy;)
	{
		if (*buffPY == ' ') i++;

		buffPY++;
	}

	buffStart = buff;	//�ҳ�Ҫ�������ַ�������ʼ��ַ
	temp = newpy;

	if (buffPY - buffStart + zifunum > 19)
	{
		sjxflag |= 0x01;		//Ҫ��ʾ��ߵ������Ρ�

		for (i = 1; i < newpy && *buffStart != 0;)
		{
			buffStart++;

			if (*buffStart == ' ')
			{
				i++;
				temp--;

				if (buffPY - buffStart + zifunum <= 20)
				{
					buffStart++;
					break;
				}
			}
		}
	}

	for (i = 0; i < 19 && *buffStart != 0; i++)  		//�����ַ�����diplaybuff
	{
		diplaybuff[i] = *buffStart;
		buffStart++;
	}

	for (; i < 20; i++) diplaybuff[i] = ' ';

	diplaybuff[i] = 0;

	while (*buffStart != 0)  		//�ж��Ƿ�Ҫ��ʾ�ұߵ������Ρ�
	{
		if (*buffStart >= 'a' && *buffStart <= 'z')
		{
			sjxflag |= 0x02;
			break;
		}

		buffStart++;
	}

	xpos = 0;

	for (j = 0, i = 1; i < temp;)  		//���������x  ����λ��
	{
		if (diplaybuff[j] == ' ')
		{
			i++;
		}

		xpos++;
		j++;
	}

	text_out_to_row_x_Language2 (MaxRowOneScr - 2, 6, (unsigned char*) diplaybuff, (unsigned char*)diplaybuff);
	reverse_area_to_row (xpos * 6 + 6, MaxRowOneScr - 2, zifunum * 6 + 2, 12);

	if (sjxflag & 0x01)
	{
		draw_pic ( (unsigned char*) leftsjx, 0, 43, 5, 7);
	}
	else
	{
		clear_area (0, 43, 5, 7);
	}

	if (sjxflag & 0x02)
	{
		draw_pic ( (unsigned char*) rightsjx, 124, 43, 5, 7);
	}
	else
	{
		clear_area (124, 43, 5, 7);
	}
}


static void CalculateCursorOffset (char srf)
{
	signed int x = cursorX, y = cursorY;

	if (srf == SRF_BiHua || srf == SRF_PY) x += 12;
	else x += 6;

	if (x >= 6 * ALineNum)
	{
		x = 0;
		y *= 13;

		if (y >= (EditAreaTotalRow + 1) * 13) y = EditAreaTotalRow * 13;
	}

#ifdef DEBUG_PRINTF
	printf ("cursorX=%d,cursorY=%d\n", x, y);
#endif

	flashcursor (x, y);
}


static u8 PinYinReadCode (char PyCode[3]) //ƴ�����뷨������
{
	char key09[10], keyflag, PYnum, strcpyflag, confirmflag = 0, rowcnt, pagecnt = 0, youcipinyinzuohe;
	char PYrowcnt, PYbuff[100];
	int i;
	const T9PY_IDX *pT9PY = NULL;
	char HaiziRightShiftmax;	//�����������ֵ
	u8 keycnt = 0;
	u8 keyval;
	u8 flag = 1;

	memset (key09, 0, sizeof (key09) );

	while (1)
	{
		keyval = GetKeyValue();

		if (keyval == 0) continue;

		if (flag == 1)
		{
			flag = 0;
			KeyEventPost_nobeep();
		}
		else
		{
			KeyEventPost();
		}

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				key09[keycnt++] = '0';
				break;

			case KEY1:
				keyflag = 1;
				key09[keycnt++] = '1';
				break;

			case KEY2:
				keyflag = 1;
				key09[keycnt++] = '2';
				break;

			case KEY3:
				keyflag = 1;
				key09[keycnt++] = '3';
				break;

			case KEY4:
				keyflag = 1;
				key09[keycnt++] = '4';
				break;

			case KEY5:
				keyflag = 1;
				key09[keycnt++] = '5';
				break;

			case KEY6:
				keyflag = 1;
				key09[keycnt++] = '6';
				break;

			case KEY7:
				keyflag = 1;
				key09[keycnt++] = '7';
				break;

			case KEY8:
				keyflag = 1;
				key09[keycnt++] = '8';
				break;

			case KEY9:
				keyflag = 1;
				key09[keycnt++] = '9';
				break;

			case KEYXING:
				keyflag = 1;
				keycnt = 1;
				key09[0] = '*';
				key09[1] = 0;
				break;

			case KEYJING:	//#�л����뷨
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return KEYJING;

			case KEY_UP:			//�����Ϸ�ҳ
				if (pagecnt && confirmflag == 2)
				{
					pagecnt--;
					rowcnt = 0;
					DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 1, pagecnt, &HaiziRightShiftmax);
				}

				break;

			case KEY_DOWN:			//�����·�ҳ
				if (pagecnt < (strlen ( (char*) pT9PY->MB) - 2) / 14 && confirmflag == 2)  				//�˴���2  Ϊ������պ�һ�����û�
				{
					pagecnt++;
					rowcnt = 0;
					DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 1, pagecnt, &HaiziRightShiftmax);
#ifdef DEBUG_PRINTF
					printf ("pT9PY->MB=%s\r\n", pT9PY->MB);
#endif
				}

				break;

			case KEY_LEFT:
				if (confirmflag == 1)  				//ƴ����������
				{
					if (PYrowcnt > 1)
					{
						PYrowcnt--;
						HighLightPY (PYbuff, PYrowcnt);
						DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 0, pagecnt, &HaiziRightShiftmax);
					}
				}
				else if (confirmflag == 2)  				//���ָ�������
				{
					if (rowcnt)
					{
						rowcnt--;
						reverse_area_to_row (6 + 18 * (rowcnt + 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * rowcnt, MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_RIGHT:
				if (confirmflag == 1)  				//ƴ����������
				{
					if (PYrowcnt < PYnum)
					{
						PYrowcnt++;
						HighLightPY (PYbuff, PYrowcnt);printf("PYbuff=%s,PYrowcnt=%d\r\n",PYbuff,PYrowcnt);
						DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 0, pagecnt, &HaiziRightShiftmax);
					}
				}
				else if (confirmflag == 2)  				//���ָ�������
				{
					if (pT9PY != NULL && rowcnt < HaiziRightShiftmax)
					{
						rowcnt++;
						reverse_area_to_row (6 + 18 * (rowcnt - 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * (rowcnt), MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_Enter:
				keyflag = 4;
				break;

			case KEY_DEL:	//ɾ����
				if (keycnt <= 1)  				//ɾ������󣬾ͷ���
				{
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);	//ƴ������ռ��������У������˳�ʱ���
					return KEY_DEL;
				}
				else 				//ɾ��һ��ƴ����ĸ
				{
					confirmflag = 1;
					keyflag = 1;
					keycnt--;
					key09[keycnt] = 0;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return keyval;
		}

		if (keyflag == 1)
		{
			if (confirmflag == 2)  				//1---7ѡ����
			{
#ifdef DEBUG_PRINTF
				printf ("key09[keycnt-1]=%c\r\n", key09[keycnt - 1]);
#endif

				if (key09[keycnt - 1] >= '1' && key09[keycnt - 1] <= '7')
				{
					i = key09[keycnt - 1] - '1';
					memset (PyCode, 0, 3);
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
#ifdef DEBUG_PRINTF
					printf ("pagecnt=%d\r\n", pagecnt);
					printf ("pT9PY->MB=%s\r\n", pT9PY->MB);
					printf ("i=%d\r\n", i);
#endif
					memcpy (PyCode, pT9PY->MB + pagecnt * 14 + i * 2, 2);
					CalculateCursorOffset (SRF_PY);
					return KEY_Enter;
				}
			}
			else 				//ƴ������
			{
				rowcnt = 0;

				if (keycnt > sizeof (key09) - 1) keycnt = sizeof (key09) - 1;

				if (keycnt == 0)
				{
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
				}
				else
				{
					strcpyflag = 0;
					youcipinyinzuohe = 0;

					for (i = 0; t9PY_index[i].T9 != NULL; i++)
					{
						if (strcmp ( (char*) t9PY_index[i].T9, key09) == 0)
						{
							if (!strcpyflag)
							{
								strcpyflag = 1;
								pT9PY = &t9PY_index[i];
								strcpy (PYbuff, (char*) t9PY_index[i].PY);
							}
							else strcat (PYbuff, (char*) t9PY_index[i].PY);

							strcat (PYbuff, " ");
							youcipinyinzuohe = 1;
						}
					}

					if (!youcipinyinzuohe)
					{
						for (i = 0; t9PY_index[i].T9 != NULL; i++)
						{
							if (my_FFstrstr ( (char*) t9PY_index[i].T9, key09) )
							{
								if (!strcpyflag)
								{
									strcpyflag = 1;
									pT9PY = &t9PY_index[i];
									strcpy (PYbuff, (char*) t9PY_index[i].PY);
								}
								else strcat (PYbuff, (char*) t9PY_index[i].PY);

								strcat (PYbuff, " ");
								youcipinyinzuohe = 1;
								break;
							}
						}

						if (!youcipinyinzuohe)
						{
							keycnt--;
							key09[keycnt] = 0;
						}
					}

					if (youcipinyinzuohe)
					{
						pagecnt = 0;
						clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
						PYnum = my_KonggeStrlen (PYbuff);

						if (PYnum)
						{
							PYrowcnt = 1;
							confirmflag = 1;
							HighLightPY (PYbuff, 1);
							DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 0, pagecnt, &HaiziRightShiftmax);
						}
					}
				}
			}
		}
		else if (keyflag == 4)  			//KEY_Enter
		{
			if (confirmflag == 1)  				//��һ�ΰ�ȷ�ϣ�������ʾ�ĺ��ּ������ֱ�ʾ��
			{
				DisplayContaiPYHaizi (PYrowcnt, &pT9PY, PYbuff, 1, pagecnt, &HaiziRightShiftmax);
				confirmflag = 2;
			}
			else 				//�ڶ��ΰ�ȷ�ϣ�ѡ��������ĺ��ַ��ء�
			{
				memset (PyCode, 0, 3);
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				memcpy (PyCode, pT9PY->MB + pagecnt * 14 + rowcnt * 2, 2);
				CalculateCursorOffset (SRF_PY);
				return KEY_Enter;
			}
		}

#ifdef DEBUG_PRINTF
		printf ("key09=%s\r\n", key09);
#endif

		KeyIsResponse();
	}
}


//0---->9  ��*�����˺���
static u8 BiHuaReadCode (char PyCode[3]) //�ʻ����뷨������
{
	char key09[15], keyflag, confirmflag = 0, rowcnt, pagecnt = 0;
	int i;
	const T9BH_IDX *pT9BH = NULL;
	char HaiziRightShiftmax;	//�����������ֵ
	u8 keycnt = 0;
	u8 keyval;
	u8 flag = 1;

	memset (key09, 0, sizeof (key09) );

	while (1)
	{
		keyval = GetKeyValue();

		if (keyval == 0) continue;

		if (flag == 1)
		{
			flag = 0;
			KeyEventPost_nobeep();
		}
		else
		{
			KeyEventPost();
		}

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				key09[keycnt++] = '0';
				break;

			case KEY1:
				keyflag = 1;
				key09[keycnt++] = '1';
				break;

			case KEY2:
				keyflag = 1;
				key09[keycnt++] = '2';
				break;

			case KEY3:
				keyflag = 1;
				key09[keycnt++] = '3';
				break;

			case KEY4:
				keyflag = 1;
				key09[keycnt++] = '4';
				break;

			case KEY5:
				keyflag = 1;
				key09[keycnt++] = '5';
				break;

			case KEY6:
				keyflag = 1;
				key09[keycnt++] = '6';
				break;

			case KEY7:
				keyflag = 1;
				key09[keycnt++] = '7';
				break;

			case KEYXING:
				keyflag = 1;
				keycnt = 1;
				key09[0] = '*';
				key09[1] = 0;
				break;

			case KEYJING:	//#�л����뷨
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return KEYJING;

			case KEY_UP:			//�����Ϸ�ҳ
				if (pagecnt && confirmflag == 2)
				{
					pagecnt--;
					rowcnt = 0;
					DisplayContaiBHHaizi (&pT9BH, key09, 1, pagecnt, &HaiziRightShiftmax);
				}

				break;

			case KEY_DOWN:			//�����·�ҳ
				if (pagecnt < (strlen ( (char*) pT9BH->MB) - 2) / 14 && confirmflag == 2)  				//�˴���2  Ϊ������պ�һ�����û�
				{
					pagecnt++;
					rowcnt = 0;
					DisplayContaiBHHaizi (&pT9BH, key09, 1, pagecnt, &HaiziRightShiftmax);
#ifdef DEBUG_PRINTF
					printf ("pT9BH->MB=%s\n", pT9BH->MB);
#endif
				}

				break;

			case KEY_LEFT:
				if (confirmflag == 2)  		//���ָ�������
				{
					if (rowcnt)
					{
						rowcnt--;
						reverse_area_to_row (6 + 18 * (rowcnt + 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * rowcnt, MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_RIGHT:
				if (confirmflag == 2)  		//���ָ�������
				{
					if (pT9BH != NULL && rowcnt < HaiziRightShiftmax)
					{
						rowcnt++;
						reverse_area_to_row (6 + 18 * (rowcnt - 1), MaxRowOneScr - 1, 12, 14);
						reverse_area_to_row (6 + 18 * (rowcnt), MaxRowOneScr - 1, 12, 14);
					}
				}

				break;

			case KEY_Enter:
				keyflag = 4;
				break;

			case KEY_DEL:	//ɾ����
				if (keycnt <= 1)  		//ɾ������󣬾ͷ���
				{
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);				//�ʻ�����ռ��������У������˳�ʱ���
					return KEY_DEL;
				}
				else 				//ɾ��һ���ʻ�
				{
					confirmflag = (keycnt - 1) * 6;
					clear_area (confirmflag, 44, 6, 6);				//������һ���ʻ�
					confirmflag = 1;
					keyflag = 1;
					keycnt--;
					key09[keycnt] = 0;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 1);
				return keyval;
		}

		if (keyflag == 1)
		{
			if (confirmflag == 2)  				//1---7ѡ����
			{
#ifdef DEBUG_PRINTF
				printf ("key09[keycnt-1]=%c\n", key09[keycnt - 1]);
#endif

				if (key09[keycnt - 1] >= '1' && key09[keycnt - 1] <= '7')
				{
					i = key09[keycnt - 1] - '1';
					memset (PyCode, 0, 3);
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
#ifdef DEBUG_PRINTF
					printf ("pagecnt=%d\n", pagecnt);
					printf ("pT9BH->MB=%s\n", pT9BH->MB);
					printf ("i=%d\n", i);
#endif
					memcpy (PyCode, pT9BH->MB + pagecnt * 14 + i * 2, 2);
					CalculateCursorOffset (SRF_PY);
					return KEY_Enter;
				}
			}
			/*else 				//�ʻ�����
			{
				rowcnt = 0;

				if (keycnt > sizeof (key09) - 1) keycnt = sizeof (key09) - 1;

				if (keycnt == 0)
				{
					clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
				}
				else
				{
					//strcpyflag=0;
					//youcipinyinzuohe=0;
					for (i = 0; t9BH_index[i].bh23456 != NULL; i++)
					{
						if (my_FFstrstr ( (char*) t9BH_index[i].bh23456, key09) )
						{
							pT9BH = &t9BH_index[i];
							DisplayContaiBHHaizi (&pT9BH, key09, 0, pagecnt, &HaiziRightShiftmax);
							confirmflag = 1;
							break;
						}
					}

					if (t9BH_index[i].bh23456 == NULL)
					{
						keycnt--;
						key09[keycnt] = 0;
					}
				}
			}*/
		}
		else if (keyflag == 4)  			//KEY_Enter
		{
			if (confirmflag == 1)  				//��һ�ΰ�ȷ�ϣ�������ʾ�ĺ��ּ������ֱ�ʾ��
			{
				DisplayContaiBHHaizi (&pT9BH, key09, 1, pagecnt, &HaiziRightShiftmax);
				confirmflag = 2;
			}
			else 				//�ڶ��ΰ�ȷ�ϣ�ѡ��������ĺ��ַ��ء�
			{
				memset (PyCode, 0, 3);
				clear_area_to_row (MaxRowOneScr - 2, MaxRowOneScr - 2);
				memcpy (PyCode, pT9BH->MB + pagecnt * 14 + rowcnt * 2, 2);
				CalculateCursorOffset (SRF_BiHua);
				return KEY_Enter;
			}
		}

#ifdef DEBUG_PRINTF
		printf ("key09=%s\n", key09);
#endif

		KeyIsResponse();
	}
}


void flashcursor (signed int x, signed int y)
{
	cursorX = x;
	cursorY = y;
}


/*static void AccordStrCalculateCursorXY(const char *receivetemp)
{
signed int x=0,y=0;

x=strlen(receivetemp);
#ifdef DEBUG_PRINTF
printf("x=%d\n",x);
#endif
if(x/ALineNum<EditAreaTotalRow){y=x/ALineNum%EditAreaTotalRow+EditAreaStartLine;}
else {y=EditAreaTotalRow+EditAreaStartLine-1;}

x=x%ALineNum*6;
y=y*13;

flashcursor(x,y);
}
*/




static void srf_strcat_insert (unsigned char *pMove, const unsigned char *PyCode)
{
	unsigned char insertlen;
	unsigned int pMovelen;

	const unsigned char *psrc;
	unsigned char *pdes;

	insertlen = strlen ( (const char*) PyCode);
	pMovelen = strlen ( (const char*) pMove);

	if (pMovelen)
	{
		psrc = pMove + pMovelen - 1;
		pdes = pMove + pMovelen + insertlen - 1;

		for (; pMovelen != 0; pMovelen--)
		{
			*pdes = *psrc;
			psrc--;
			pdes--;
		}
	}

	memcpy (pMove, PyCode, insertlen);
}


#else
static void srf_strcat_insert (unsigned char *pMove, const unsigned char *PyCode)
{
	unsigned char insertlen;
	unsigned int pMovelen;

	const unsigned char *psrc;
	unsigned char *pdes;

	insertlen = strlen ( (const char*) PyCode);
	pMovelen = strlen ( (const char*) pMove);

	if (pMovelen)
	{
		psrc = pMove + pMovelen - 1;
		pdes = pMove + pMovelen + insertlen - 1;

		for (; pMovelen != 0; pMovelen--)
		{
			*pdes = *psrc;
			psrc--;
			pdes--;
		}
	}

	memcpy (pMove, PyCode, insertlen);
}


static void CalculateCursorOffset (char srf)
{
	signed int x = cursorX, y = cursorY;

	if (srf == SRF_BiHua || srf == SRF_PY) x += 12;
	else x += 6;

	if (x >= 6 * ALineNum)
	{
		x = 0;
		y *= 13;

		if (y >= (EditAreaTotalRow + 1) * 13) y = EditAreaTotalRow * 13;
	}

#ifdef DEBUG_PRINTF
	printf ("cursorX=%d,cursorY=%d\n", x, y);
#endif

	flashcursor (x, y);
}

void flashcursor (signed int x, signed int y)
{
	cursorX = x;
	cursorY = y;
}

/*����ָ����в���༭*/
/*���������������abc  ��ABC  ���뷨��*/
static void my_AccordPointInsertEdit (const u8 *TheFirstAddrOfBuff, const u8 *pMove, char StartLine, char EndLine, u8 *cursorx, u8 *cursory)
{
	u8 totalline;	//�༭���м���
	int bytenum;	//��buff  ͷ����괦�ж��ٸ��ַ�
	u8 byteline;	//��buff  ͷ����괦��Ҫ���ٸ�����ʾ
	//int bytetotal;	//buff  �ܹ��ж��ٸ��ַ�
	u8 i, j;
	const u8 *display;
	u8 disp[23];

	*cursorx = 0;
	*cursory = 0;

	totalline = EndLine - StartLine + 1;
	bytenum = pMove - TheFirstAddrOfBuff;
	//bytetotal=strlen((char const*)TheFirstAddrOfBuff);

	byteline = bytenum / ALineNum;

	if (bytenum % ALineNum) byteline++;

	display = TheFirstAddrOfBuff;	//�ҳ���Ҫ��ʾ�ĵ�ַ

	if (byteline > totalline)
	{
		for (i = 0; i < byteline - totalline; i++)
		{
			for (j = 0; j < ALineNum; j++, display++)
			{
				if (*display > 0x80)
				{
					display++;
					j++;
				}
			}
		}
	}

#ifdef DEBUG_PRINTF
	printf ("display=%s\n", display);
#endif

	if (*display != 0)  		//������ַ�
	{
		for (i = 0; i < totalline; i++)  			//��ʾpMove  ֮ǰ֮������" ��ʾ��Χ֮��"  ���ַ�
		{
			for (j = 0; j < ALineNum && *display != 0;)
			{
				if (*display > 0x80)
				{
					disp[j] = *display;
					j++;
					display++;

					if (display == pMove)
					{
						*cursory = i;
						*cursorx = j;
					}
				}

				disp[j] = *display;
				j++;
				display++;

				if (display == pMove)
				{
					*cursory = i;
					*cursorx = j;
				}
			}

			for (; j < ALineNum + 2; j++) disp[j] = ' ';			//�˴�ALineNum+1  Ϊ��ȥ��ɾ���ַ��ǣ���������ʾ������ֵ�����

			disp[j] = 0;
#ifdef DEBUG_PRINTF
			printf ("disline=%s\n", disp);
#endif
			text_out_to_row_Language2 (StartLine + i, disp, disp);
		}
	}
	else 		//���û�ַ������п�����ɾ�����ˣ�����Ļ��ʣһ���ַ�
	{
		text_out_to_row_Language2 (StartLine, "   ", "   ");
	}

#ifdef DEBUG_PRINTF
	printf ("bytenum=%d\n", bytenum);
#endif

	*cursorx *= 6;
	*cursory += StartLine;
	*cursory *= 13;
	flashcursor (*cursorx, *cursory);
}

#endif

static void flashguangbiao_to_row (u8 x, u8 row)
{
	flashcursor (x, 13 * row);
}

static u8 abcABCflag = 0;

static u8 abcReadCode (const u8 *BuffTheFirstAddr, u8 *pMove)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.:%1@/?;\'\"|\\{[}]=+-_)(*&^$#!~`<>",
		"abc2",
		"def3",
		"ghi4",
		"jkl5",
		"mno6",
		"pqrs7",
		"tuv8",
		"wxyz9"
	};

	CalculateCursorOffset (SRF_abc);	//�������������뵽����ض��᷵��һ��asccii  ��
	x = pMove - BuffTheFirstAddr;

	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert (pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, 1, 2, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12);				//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}

static u8 ABCReadCode (const u8 *BuffTheFirstAddr, u8 *pMove)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.:%1@/?;\'\"|\\{[}]=+-_)(*&^$#!~`<>",
		"ABC2",
		"DEF3",
		"GHI4",
		"JKL5",
		"MNO6",
		"PQRS7",
		"TUV8",
		"WXYZ9"
	};

	CalculateCursorOffset (SRF_ABC);	//�������������뵽����ض��᷵��һ��asccii  ��
	x = pMove - BuffTheFirstAddr;
#ifdef DEBUG_PRINTF
	printf ("len=%d\n", x);
#endif
	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert ( (unsigned char*) pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, 1, 2, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12);				//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}

static u8 _123ReadCode (u8 PyCode[3], u8 keyval)
{
	memset (PyCode, 0, 3);

	switch (keyval)
	{
		case KEY0:
			PyCode[0] = '0';
			break;

		case KEY1:
			PyCode[0] = '1';
			break;

		case KEY2:
			PyCode[0] = '2';
			break;

		case KEY3:
			PyCode[0] = '3';
			break;

		case KEY4:
			PyCode[0] = '4';
			break;

		case KEY5:
			PyCode[0] = '5';
			break;

		case KEY6:
			PyCode[0] = '6';
			break;

		case KEY7:
			PyCode[0] = '7';
			break;

		case KEY8:
			PyCode[0] = '8';
			break;

		case KEY9:
			PyCode[0] = '9';
			break;

		case KEYXING:
			PyCode[0] = '.';
			break;
	}

	if ( (PyCode[0] >= '0' && PyCode[0] <= '9') || PyCode[0] == '.')
	{
		CalculateCursorOffset (SRF_123);
		return KEY_Enter;
	}
	else return KEY_ReturnInitInterface;
}

static u8 _123TimeInput (u8 PyCode[3], u8 keyval)
{
	memset (PyCode, 0, 3);

	switch (keyval)
	{
		case KEY0:
			PyCode[0] = '0';
			break;

		case KEY1:
			PyCode[0] = '1';
			break;

		case KEY2:
			PyCode[0] = '2';
			break;

		case KEY3:
			PyCode[0] = '3';
			break;

		case KEY4:
			PyCode[0] = '4';
			break;

		case KEY5:
			PyCode[0] = '5';
			break;

		case KEY6:
			PyCode[0] = '6';
			break;

		case KEY7:
			PyCode[0] = '7';
			break;

		case KEY8:
			PyCode[0] = '8';
			break;

		case KEY9:
			PyCode[0] = '9';
			break;

		case KEYXING:
			PyCode[0] = ':';
			break;
	}

	if ( (PyCode[0] >= '0' && PyCode[0] <= '9') || PyCode[0] == ':')
	{
		CalculateCursorOffset (SRF_123);
		return KEY_Enter;
	}
	else return KEY_ReturnInitInterface;
}

typedef struct
{
	const char srf[5];
	char Enable;
} T_ShuRuFa;


static u8 *GetSrfString (u8 currentSrf)
{
	if (currentSrf == SRF_PY) return "ƴ��";
	else if (currentSrf == SRF_123) return "123 ";
	else if (currentSrf == SRF_abc) return "abc ";
	else if (currentSrf == SRF_ABC) return "ABC ";
	else if (currentSrf == SRF_BiHua) return "�ʻ�";
	else return "abc ";
}

static void DisplaySrfAndInput (u8 currentSrf)
{
	clear_area_to_row (MaxRowOneScr - 1, MaxRowOneScr - 1);
	text_out_to_row_x (MaxRowOneScr - 1, 0, GetSrfString (currentSrf) );
	reverse_area_to_row (0, MaxRowOneScr - 1, 25, 16);
	text_out_to_row_x (MaxRowOneScr - 1, 60, "input...");
}

static u8 SwitchSrf (u8 VolidSrf, u8 currentSrf)
{
	if (currentSrf == SRF_PY)
	{
		if (VolidSrf & SRF_123) return SRF_123;
		else if (VolidSrf & SRF_abc) return SRF_abc;
		else if (VolidSrf & SRF_ABC) return SRF_ABC;
		else if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else return SRF_PY;
	}
	else if (currentSrf == SRF_123)
	{
		if (VolidSrf & SRF_abc) return SRF_abc;
		else if (VolidSrf & SRF_ABC) return SRF_ABC;
		else if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else if (VolidSrf & SRF_PY) return SRF_PY;
		else return SRF_123;
	}
	else if (currentSrf == SRF_abc)
	{
		if (VolidSrf & SRF_ABC) return SRF_ABC;
		else if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else if (VolidSrf & SRF_PY) return SRF_PY;
		else if (VolidSrf & SRF_123) return SRF_123;
		else return SRF_abc;
	}
	else if (currentSrf == SRF_ABC)
	{
		if (VolidSrf & SRF_BiHua) return SRF_BiHua;
		else if (VolidSrf & SRF_PY) return SRF_PY;
		else if (VolidSrf & SRF_123) return SRF_123;
		else if (VolidSrf & SRF_abc) return SRF_abc;
		else return SRF_ABC;
	}
	else if (currentSrf == SRF_BiHua)
	{
		if (VolidSrf & SRF_PY) return SRF_PY;
		else if (VolidSrf & SRF_123) return SRF_123;
		else if (VolidSrf & SRF_abc) return SRF_abc;
		else if (VolidSrf & SRF_ABC) return SRF_ABC;
		else return SRF_BiHua;
	}
	else
	{
		return SRF_abc;
	}
}


static void flightcursor (void)
{
	static unsigned int PreviousMs;
	unsigned int CurrentMs;

	CurrentMs = my_GetCurrentMs();

	if (CurrentMs > PreviousMs && CurrentMs - PreviousMs >= 500)
	{
		PreviousMs = CurrentMs;
		reverse_area (cursorX, cursorY, 1, 12);
	}
}

u8 _GetString_abcABC123PYWuBi (u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	int x;
	u8 keyflag;
	u8 cursorx, cursory;
	u8 inputCode[3];
	u8 i = 0;
	u8 *pMove;
	u8 ChineseThinkFlag = 0;
	u8 keyval;
	u8 currentSrf;

	currentSrf = DefaultSrf;
	DisplaySrfAndInput (currentSrf);

	if (HaveoldFlag)
	{
		x = strlen ( (sc8*) receive);
		//text_out_to_row(1,receive);
		memset (receive + x, 0, recSize - x);		//ϴ����������receive  ���������õ�β�����ݡ�
	}
	else
	{
		x = 0;
		memset (receive, 0, recSize);
	}

	flashguangbiao_to_row (0, EditAreaStartLine);
	pMove = receive + x;
	PostKey (KEY_pseudo);

	while (1)
	{
		flightcursor();
		keyval = GetKeyValue();

		if (keyval == KEY_NONE) continue;

		if (keyval != KEY_pseudo)
		{
			//KeyEventPost();
			if (beepKG[0] == '1')
			{
				if (abcABCflag == 0) BeepNormal();

				abcABCflag = 0;
			}

			kmy_LcdBlackLightOn();
			kmy_AutoOffLcdLight (120);
			kmy_AutoPostKey (120);
		}

		keyflag = KEY_NONE;

		switch (keyval)
		{
			case KEY0:
			case KEY1:
			case KEY2:
			case KEY3:
			case KEY4:
			case KEY5:
			case KEY6:
			case KEY7:
			case KEY8:
			case KEY9:
			case KEYXING:
				if (ChineseThinkFlag == 0)
				{
	loop:

					if (strlen ( (sc8*) receive) < recSize - 1)  		//�˴�recSize  Ϊ�ַ���������
					{
						if (currentSrf == SRF_PY)  						//ƴ��
						{
#ifdef AddBiHuaPinYin
							PostKey (keyval);
							keyval = PinYinReadCode ( (char*) inputCode);
#endif
						}
						else if (currentSrf == SRF_BiHua)  			//�ʻ�
						{
#ifdef AddBiHuaPinYin
							PostKey (keyval);
							keyval = BiHuaReadCode ( (char*) inputCode);
#endif
						}
						else if (currentSrf == SRF_abc)  				//abc
						{
							pMove++;
							PostKey (keyval);
							keyval = abcReadCode (receive, pMove);

							if (keyval != KEY_NONE && keyval != KEYJING)
							{
								goto loop;
							}
						}
						else if (currentSrf == SRF_ABC)  				//ABC
						{
							pMove++;
							PostKey (keyval);
							keyval = ABCReadCode (receive, pMove);

							if (keyval != KEY_NONE && keyval != KEYJING)
							{
								goto loop;
							}
						}
						else if (currentSrf == SRF_123)  				//123
						{
							keyval = _123ReadCode (inputCode, keyval);
						}

						if (keyval == KEY_Enter)
						{
							srf_strcat_insert (pMove, inputCode);

							if (*pMove > 0x80) pMove += 2;
							else pMove++;

							keyflag = 2;
						}
						else if (keyval == KEY_DEL)
						{
							keyflag = 2;
						}
						else if (keyval == KEYJING)
						{
							keyflag = 1;
						}
					}
				}

				break;

			case KEYJING:	//#�л����뷨
				keyflag = 1;
				break;

			case KEY_Enter:	//ȷ�Ϸ���
				//if(strlen((sc8*)receive)!=0){	//��������ַ�Ϊ�գ����ð�ȷ�ϼ�����
				//KeyIsResponse();
				return KEY_Enter;
				//}
				//break;

			case KEY_UP:			//�������
				if (ChineseThinkFlag == 0)
				{
					if (pMove - receive > ALineNum)
					{
						for (i = 0; i < ALineNum; i++)
						{
							if (* (pMove - 1) > 0x80)  							//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�
							{
								pMove--;
								i++;
								//if((pMove-receivetemp)%ALineNum==0)pMove++;
							}

							pMove--;
						}
					}
				}

				break;

			case KEY_DOWN:			//�������
				if (ChineseThinkFlag == 0)
				{
					for (i = 0; i < ALineNum && *pMove != 0; i++)
					{
						if (*pMove > 0x80)
						{
							pMove++;
							i++;
							//if((pMove-receivetemp)%ALineNum==0)pMove++;
						}

						pMove++;
					}
				}

				break;

			case KEY_LEFT:			//�������
				if (pMove > receive)
				{
					if (* (pMove - 1) > 0x80) pMove--;				//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�

					pMove--;
				}

				break;

			case KEY_RIGHT:			//�������
				if (*pMove)
				{
					if (*pMove > 0x80) pMove++;

					pMove++;
				}

				break;

				//case KEY_F4:
				//ChineseThinkFlag=1;
				//break;

			case KEY_DEL:
				x = strlen ( (sc8*) receive);

				if (x != 0)
				{
					if (pMove > receive)
					{
						if (*pMove != 0)  						//������ַ���֮��ɾ��
						{
							if (* (pMove - 1) > 0x80)
							{
								pMove -= 2;
								my_strcpy_DeleteTailByte (pMove, pMove + 2);
							}
							else
							{
								pMove -= 1;
								my_strcpy_DeleteTailByte (pMove, pMove + 1);
							}
						}
						else
						{
							if (pMove > receive && * (pMove - 1) > 0x80)  							//delete a Chinese character
							{
								pMove--;
								*pMove = 0;
							}

							pMove--;
							*pMove = 0;
						}
					}
				}
				else
				{
					return KEY_LEFT;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1 || (keyflag == 2 && currentSrf != 4) )
		{
			if (keyflag == 1)
			{
				currentSrf = SwitchSrf (srfFlag, currentSrf);
			}

			DisplaySrfAndInput (currentSrf);
		}

		my_AccordPointInsertEdit (receive, pMove, 1, 2, &cursorx, &cursory);
		KeyIsResponse();
	}
}
u8 _GetString_123TimeInput (u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	int x;
	u8 keyflag;
	u8 cursorx, cursory;
	u8 inputCode[3];
	u8 i = 0;
	u8 *pMove;
	u8 ChineseThinkFlag = 0;
	u8 keyval;
	u8 currentSrf;

	currentSrf = DefaultSrf;
	DisplaySrfAndInput (currentSrf);

	if (HaveoldFlag)
	{
		x = strlen ( (sc8*) receive);
		//text_out_to_row(1,receive);
		memset (receive + x, 0, recSize - x);		//ϴ����������receive  ���������õ�β�����ݡ�
	}
	else
	{
		x = 0;
		memset (receive, 0, recSize);
	}

	flashguangbiao_to_row (0, EditAreaStartLine);
	pMove = receive + x;
	PostKey (KEY_pseudo);

	while (1)
	{
		flightcursor();
		keyval = GetKeyValue();

		if (keyval == KEY_NONE) continue;

		if (keyval != KEY_pseudo)
		{
			//KeyEventPost();
			if (beepKG[0] == '1')
			{
				if (abcABCflag == 0) BeepNormal();

				abcABCflag = 0;
			}

			kmy_LcdBlackLightOn();
			kmy_AutoOffLcdLight (120);
			kmy_AutoPostKey (120);
		}

		keyflag = KEY_NONE;

		switch (keyval)
		{
			case KEY0:
			case KEY1:
			case KEY2:
			case KEY3:
			case KEY4:
			case KEY5:
			case KEY6:
			case KEY7:
			case KEY8:
			case KEY9:
			case KEYXING:
				if (ChineseThinkFlag == 0)
				{

					if (strlen ( (sc8*) receive) < recSize - 1)  		//�˴�recSize  Ϊ�ַ���������
					{						
						 if (currentSrf == SRF_123)  				//123
						{
							keyval = _123TimeInput (inputCode, keyval);
						}

						if (keyval == KEY_Enter)
						{
							srf_strcat_insert (pMove, inputCode);

							if (*pMove > 0x80) pMove += 2;
							else pMove++;

							keyflag = 2;
						}
						else if (keyval == KEY_DEL)
						{
							keyflag = 2;
						}
						else if (keyval == KEYJING)
						{
							keyflag = 1;
						}
					}
				}

				break;

			case KEYJING:	//#�л����뷨
				keyflag = 1;
				break;

			case KEY_Enter:	//ȷ�Ϸ���
				//if(strlen((sc8*)receive)!=0){	//��������ַ�Ϊ�գ����ð�ȷ�ϼ�����
				//KeyIsResponse();
				return KEY_Enter;
				//}
				//break;

			case KEY_UP:			//�������
				if (ChineseThinkFlag == 0)
				{
					if (pMove - receive > ALineNum)
					{
						for (i = 0; i < ALineNum; i++)
						{
							if (* (pMove - 1) > 0x80)  							//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�
							{
								pMove--;
								i++;
								//if((pMove-receivetemp)%ALineNum==0)pMove++;
							}

							pMove--;
						}
					}
				}

				break;

			case KEY_DOWN:			//�������
				if (ChineseThinkFlag == 0)
				{
					for (i = 0; i < ALineNum && *pMove != 0; i++)
					{
						if (*pMove > 0x80)
						{
							pMove++;
							i++;
							//if((pMove-receivetemp)%ALineNum==0)pMove++;
						}

						pMove++;
					}
				}

				break;

			case KEY_LEFT:			//�������
				if (pMove > receive)
				{
					if (* (pMove - 1) > 0x80) pMove--;				//GB2312  �ǿ��Եģ�GB18030  �����ж��ǲ��еġ�

					pMove--;
				}

				break;

			case KEY_RIGHT:			//�������
				if (*pMove)
				{
					if (*pMove > 0x80) pMove++;

					pMove++;
				}

				break;

				//case KEY_F4:
				//ChineseThinkFlag=1;
				//break;

			case KEY_DEL:
				x = strlen ( (sc8*) receive);

				if (x != 0)
				{
					if (pMove > receive)
					{
						if (*pMove != 0)  						//������ַ���֮��ɾ��
						{
							if (* (pMove - 1) > 0x80)
							{
								pMove -= 2;
								my_strcpy_DeleteTailByte (pMove, pMove + 2);
							}
							else
							{
								pMove -= 1;
								my_strcpy_DeleteTailByte (pMove, pMove + 1);
							}
						}
						else
						{
							if (pMove > receive && * (pMove - 1) > 0x80)  							//delete a Chinese character
							{
								pMove--;
								*pMove = 0;
							}

							pMove--;
							*pMove = 0;
						}
					}
				}
				else
				{
					return KEY_LEFT;
				}

				break;

			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1 || (keyflag == 2 && currentSrf != 4) )
		{
			if (keyflag == 1)
			{
				currentSrf = SwitchSrf (srfFlag, currentSrf);
			}

			DisplaySrfAndInput (currentSrf);
		}

		my_AccordPointInsertEdit (receive, pMove, 1, 2, &cursorx, &cursory);
		KeyIsResponse();
	}
}

static u8 my_abcReadCode (const u8 *BuffTheFirstAddr, u8 *pMove, char row)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.@1/?:;\'\"|\\{[}]=+-_)(*&^%$#!~`<>",
		"abc2",
		"def3",
		"ghi4",
		"jkl5",
		"mno6",
		"pqrs7",
		"tuv8",
		"wxyz9"
	};

	CalculateCursorOffset (SRF_abc);	//�������������뵽����ض��᷵��һ��asccii  ��
	x = pMove - BuffTheFirstAddr;

	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert (pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, row, row, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12);				//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}

static u8 my_ABCReadCode (const u8 *BuffTheFirstAddr, u8 *pMove, char row)
{
	u8 prekey = 0, curkey = 0, keyflag;
	u8 curpos = 0;
	u8 x, y;
	u8 temp[2] = {0, 0};
	unsigned int PreviousMs, CurrentMs;
	u8 keyval;
	u8 flag = 1;

	const char *ABCcode[10] =
	{
		" 0",
		",.@1/?:;\'\"|\\{[}]=+-_)(*&^%$#!~`<>",
		"ABC2",
		"DEF3",
		"GHI4",
		"JKL5",
		"MNO6",
		"PQRS7",
		"TUV8",
		"WXYZ9"
	};

	CalculateCursorOffset (SRF_ABC);	//�������������뵽����ض��᷵��һ��asccii	��
	x = pMove - BuffTheFirstAddr;
#ifdef DEBUG_PRINTF
	printf ("len=%d\n", x);
#endif
	PreviousMs = CurrentMs = my_GetCurrentMs();

	while (1)
	{
		CurrentMs = my_GetCurrentMs();

		if (CurrentMs - PreviousMs >= 500)
		{
			goto tuichu;
		}

		keyval = GetKeyValue();

		if (keyval == 0) continue;

		PreviousMs = CurrentMs;

		if (flag == 0) KeyEventPost();
		else flag = 0;

		keyflag = 0;

		switch (keyval)
		{
			case KEY0:
				keyflag = 1;
				prekey = curkey;
				curkey = '0';
				break;

			case KEY1:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY2:
				keyflag = 1;
				prekey = curkey;
				curkey = '2';
				break;

			case KEY3:
				keyflag = 1;
				prekey = curkey;
				curkey = '3';
				break;

			case KEY4:
				keyflag = 1;
				prekey = curkey;
				curkey = '4';
				break;

			case KEY5:
				keyflag = 1;
				prekey = curkey;
				curkey = '5';
				break;

			case KEY6:
				keyflag = 1;
				prekey = curkey;
				curkey = '6';
				break;

			case KEY7:
				keyflag = 1;
				prekey = curkey;
				curkey = '7';
				break;

			case KEY8:
				keyflag = 1;
				prekey = curkey;
				curkey = '8';
				break;

			case KEY9:
				keyflag = 1;
				prekey = curkey;
				curkey = '9';
				break;

			case KEYXING:
				keyflag = 1;
				prekey = curkey;
				curkey = '1';
				break;

			case KEY_Enter:
				goto tuichu;

			case KEYJING:
			case KEY_WaitTimeout:
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
		}

		if (keyflag == 1)
		{
			if (prekey != 0 && prekey != curkey)
			{
				PostKey (keyval);
				abcABCflag = 1;
				return KEY_NONE;
			}
			else
			{
				temp[0] = * (ABCcode[curkey - '0'] + curpos);
				curpos++;				//"abc2" ֮���������λ��

				if (prekey == 0)
				{
					srf_strcat_insert ( (unsigned char*) pMove - 1, (unsigned char*) temp);
				}
				else
				{
					if (curpos > strlen (ABCcode[curkey - '0']) - 1) curpos = 0;

					memcpy (pMove - 1, temp, 1);
				}

				my_AccordPointInsertEdit (BuffTheFirstAddr, pMove, row, row, &x, &y);
				x -= 6;
#ifdef DEBUG_PRINTF
				printf ("x=%d  y=%d\n", x, y);
#endif

				if (x >= ALineNum * 6)
				{
					x = 0;

					if (y < (EditAreaTotalRow + EditAreaStartLine - 1) * 13) y += 13;
				}

				reverse_area (x, y, 7, 12); 			//���Թ�괦�ַ�
			}
		}

#ifdef DEBUG_PRINTF
		printf ("curkey=%c\n", curkey);
#endif

		KeyIsResponse();
	}

tuichu:
	KeyIsResponse();
	reverse_area (x, y, 7, 11);

	return KEY_NONE;
}


char GetRecjectReasonAndInput(void)
{
	char ReasonTable[15][MENU_COL]={0};
	char rejectNum=0;
	char *pMove;
	char keyval=0;
	char cursor_row=0;	
	char cursor_index=0;
	char i=0;
	char flashflag=0;
	char index=0;
	char keyflag=0;
//	unsigned char x=0,y=0;

	clear_lcd();
	GetRejectReason(ReasonTable,(char*)RejectReason,&rejectNum);
//	printf("rejectNum=%d\r\n%s\r\n",rejectNum,RejectReason);
	if(rejectNum==0)
	{
		rejectNum=1;
	}
	
	cursor_index=rejectNum-1;	
	index=rejectNum-1;
	
	flashguangbiao_to_row (0, 0);
	if(rejectNum>4)
	{
		cursor_row=4;
	}
	else
	{
		cursor_index=4;
		cursor_row=index;
	}
	
	pMove = ReasonTable[index] + strlen(ReasonTable[index]);
	cursorX=6*strlen(ReasonTable[index]);
	if(index<=4)
	{
		cursorY=13*(index%5);
	}
	else
	{
		cursorY=13*4;
	}
	
	flashflag=1;
//	printf("cursor_row=%d\r\n",cursor_row);
//	printf("index=%d,cursor_index=%d,rejectNum=%d\r\n",index,cursor_index,rejectNum);

	while (1)
	{
		if(flashflag==1)
		{		
			flashflag=0;
			clear_lcd();
			for(i=0;i<5;i++)
			{
				text_out_to_row(i,(unsigned char*)ReasonTable[cursor_index+i-4]);
			}
		}
		else if(flashflag==2)
		{
			flashflag=0;
			clear_area_to_row(cursor_row,cursor_row);
			text_out_to_row(cursor_row,(unsigned char*)ReasonTable[cursor_index+cursor_row-4]);
		}
		else if(flashflag==3)
		{
			flashflag=0;
			clear_area_to_row(cursor_row+1,cursor_row+1);
			text_out_to_row(cursor_row+1,(unsigned char*)ReasonTable[cursor_index+cursor_row+1-4]);
		}
		else if(flashflag==4)
		{
			flashflag=0;
			clear_area_to_row(cursor_row-1,cursor_row-1);
			text_out_to_row(cursor_row-1,(unsigned char*)ReasonTable[cursor_index+cursor_row-1-4]);
		}
loop:		
		flightcursor();
		keyval = kmy_GetKeyValue();
		if (keyval == KEY_NONE) continue;
		KeyEventPost();
		switch (keyval)
		{
			case KEY0:
			case KEY1:
			case KEY2:
			case KEY3:
			case KEY4:
			case KEY5:
			case KEY6:
			case KEY7:
			case KEY8:
			case KEY9:
			case KEYXING:
				
				if(strlen(ReasonTable[index])<20)
				{
					pMove++;
					PostKey (keyval);
					if(keyflag==0)
					{
						keyval = my_abcReadCode ((u8*)ReasonTable[index], (u8*)pMove,cursor_row);
					}
					else 
					{
						keyval = my_ABCReadCode ((u8*)ReasonTable[index], (u8*)pMove,cursor_row);
					}
					
					if (keyval != KEY_NONE && keyval != KEYJING)
					{
						goto loop;
					}
				}
				
				break;
			case KEYJING:
				keyflag++;
				keyflag=keyflag%2;
				
				break;
			case KEY_UP:
				
				if(index>0)
				{
					index--;
				}
				if(cursor_row==0)
				{
					if(cursor_index>4)
					{
						cursor_index--;
						flashflag=1;
					}
				}
				if(cursor_row>0)
				{
					cursor_row--;
					cursorY -=13;
					flashflag=3;
				}
				if(cursorX>(6*strlen(ReasonTable[index])))
				{
					cursorX=6*strlen(ReasonTable[index]);
				}
//				printf("cursor_row=%d\r\n",cursor_row);
//				printf("index=%d,cursor_index=%d,rejectNum=%d\r\n",index,cursor_index,rejectNum);
				if(cursorX<6)
				{
					pMove = ReasonTable[index] ;
				}
				else
				{
					pMove = ReasonTable[index] + cursorX/6;
				}
//				printf("pMove=%s\r\n",pMove);
				break;
				
			case KEY_DOWN:
				if(rejectNum<15)
				{
					if((index==rejectNum)||(rejectNum<=4&&index==rejectNum-1))
					{
						if(strlen(ReasonTable[index])>0)
						{
							rejectNum++;
						}
					}
					
				}
				
				if(cursor_row==4)
				{			
					if(cursor_index<rejectNum)
					{
						if((cursor_row==rejectNum-1)&&(strlen(ReasonTable[index])==0))
						{
						}
						else
						{
							cursor_index++; 							
							flashflag=1;
						}						
					}
				}
				if(index<rejectNum)
				{
					if((cursor_row==rejectNum-1)&&(strlen(ReasonTable[index])==0))
					{

					}
					else
					{
						index++;
					}
				}
				if(cursor_row<4)
				{
					if((cursor_row==rejectNum-1)&&(strlen(ReasonTable[index])==0))
					{

					}
					else
					{
						cursor_row++;					
						cursorY +=13;
					}
										
					flashflag=4;					
				}
				if(cursorX>(6*strlen(ReasonTable[index])))
				{
					cursorX=6*strlen(ReasonTable[index]);
				}
	//			printf("cursor_row=%d\r\n",cursor_row);
	//			printf("index=%d,cursor_index=%d,rejectNum=%d\r\n",index,cursor_index,rejectNum);
				if(cursorX<6)
				{
					pMove = ReasonTable[index] ;
				}
				else
				{
					pMove = ReasonTable[index] + cursorX/6;
				}
	//			printf("pMove=%s\r\n",pMove);

				break;
				
			case KEY_LEFT:
				if(cursorX>=6)
				{
					pMove--;
					flashflag=2;
					cursorX -=6;
				}
	//			printf("pMove=%s\r\n",pMove);
				
				break;
				
			case KEY_RIGHT: 			
				if(cursorX<6*strlen(ReasonTable[index]))
				{				
					pMove++;
					cursorX +=6;
					flashflag=2;
				}
				
	//			printf("pMove=%s\r\n",pMove);
				break;
				
			case KEY_Enter:
				memset(RejectReason,0,sizeof(RejectReason));
				for(i=0;i<rejectNum;i++)
				{
					if(strlen(ReasonTable[i])>0)
					{
						strcat((char*)RejectReason,ReasonTable[i]);
						strcat((char*)RejectReason,";");
					}
				}
				return keyval;
				
			case KEY_DEL:
				if(pMove!=ReasonTable[index])
				{
					if(cursorX>=6)
					{
						pMove--;
						flashflag=2;
						cursorX -=6;
						
						my_strcpy_DeleteTailByte ((unsigned char*)pMove,(unsigned char*)pMove+1);
					}
				}
				break;
				
			case KEY_ReturnPrevious:
			case KEY_ReturnInitInterface:
				return keyval;
				
			default:break;
		}

	}
	


}

	


void abcABC123PYWuBiArgDeInit (abcABC123PYWuBiArgument *arg, u8 *buff, u8 Size)
{
	(*arg).LocalTitle = "������";
	(*arg).OtherTitle = "Input";
	(*arg).receive = buff;
	(*arg).recSize = Size;
	(*arg).srfFlag = SRF_123 | SRF_ABC | SRF_abc;
	(*arg).DefaultSrf = SRF_123;
	(*arg).clearlcdflag = 1;
	(*arg).HaveoldFlag = 0;
}


u8 GetString_abcABC123PYWuBi2 (abcABC123PYWuBiArgument *arg)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_GetString_abcABC123PYWuBi ( (*arg).srfFlag, (*arg).DefaultSrf, (*arg).receive, (*arg).recSize, (*arg).HaveoldFlag) );
}


u8 GetString_abcABC123PYWuBi (const u8 *Title, u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	clear_lcd();

	if (Title != NULL) DrawTitle_to_row_Language2 (0, Title, Title);

	KeyIsResponse();

	return (_GetString_abcABC123PYWuBi (srfFlag, DefaultSrf, receive, recSize, HaveoldFlag) );
}
u8 GetString_123TimeInput (const u8 *Title, u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	clear_lcd();

	if (Title != NULL) DrawTitle_to_row_Language2 (0, Title, Title);

	KeyIsResponse();

	return (_GetString_123TimeInput (srfFlag, DefaultSrf, receive, recSize, HaveoldFlag) );
}

u8 GetString_abcABC123PYWuBi_Language2 (const u8 *LocalTitle, const u8 *OtherTitle, u8 srfFlag, u8 DefaultSrf, u8 *receive, u8 recSize, u8 HaveoldFlag)
{
	clear_lcd();
	DrawTitle_to_row_Language2 (0, LocalTitle, OtherTitle);
	KeyIsResponse();

	return (_GetString_abcABC123PYWuBi (srfFlag, DefaultSrf, receive, recSize, HaveoldFlag) );
}


/*��x  λ�ÿ�ʼ��ʾ*/
static u8 _PassWordInput_XposStartDisplay (u8 *receive, u8 recSize, u8 xingflag, u8 DiplayRow, u8 Xpos, u8 argkeyval)
{
	u8 i;
	u8 inputSize;
	u8 displaybuff[22];
	u8 ClearFlag = 0;
	u8 keyval;

	inputSize = recSize > 21 ? 21 : recSize;
	memset (receive, 0, inputSize);
	i = 0;

	while (1)
	{
		if (argkeyval == KEY_NONE)
		{
			keyval = GetKeyValue();
		}
		else
		{
			keyval = argkeyval;
			argkeyval = KEY_NONE;
		}

		if (keyval == 0) continue;

		KeyEventPost();

		switch (keyval)
		{
			case KEY0:
				if (i < inputSize)
				{
					receive[i] = '0';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY1:
				if (i < inputSize)
				{
					receive[i] = '1';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY2:
				if (i < inputSize)
				{
					receive[i] = '2';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY3:
				if (i < inputSize)
				{
					receive[i] = '3';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY4:
				if (i < inputSize)
				{
					receive[i] = '4';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY5:
				if (i < inputSize)
				{
					receive[i] = '5';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY6:
				if (i < inputSize)
				{
					receive[i] = '6';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY7:
				if (i < inputSize)
				{
					receive[i] = '7';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY8:
				if (i < inputSize)
				{
					receive[i] = '8';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY9:
				if (i < inputSize)
				{
					receive[i] = '9';
					i++;
					receive[i] = 0;
				}

				break;

			case KEYXING:
				if (i < inputSize)
				{
					receive[i] = '.';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY_DEL:
				if (i > 0)
				{
					i--;
					receive[i] = 0;
					ClearFlag = 1;
				}

				//else{KeyIsResponse();return KEY_ReturnPrevious;}
				break;

			case KEY_Enter:
				if (strlen ( (sc8*) receive) != 0)  	//��������ַ�Ϊ�գ����ð�ȷ�ϼ�����
				{
					KeyIsResponse();
					return KEY_Enter;
				}

				break;

			case KEY_ReturnPrevious:
				KeyIsResponse();
				return KEY_ReturnPrevious;

			case KEY_ReturnInitInterface:
			case KEY_WaitTimeout:
				KeyIsResponse();
				return KEY_ReturnInitInterface;
		}

		if (ClearFlag == 1)
		{
			ClearFlag = 0;
			clear_area (Xpos, DiplayRow * ALineContainDotLine, ALinePixNum - Xpos, ALineContainDotLine);
		}

		if (xingflag)
		{
			memset (displaybuff, '*', i);
			displaybuff[i] = 0;
			text_out_to_row_x (DiplayRow, Xpos, displaybuff);
		}
		else
		{
			text_out_to_row_x (DiplayRow, Xpos, receive);
		}

		KeyIsResponse();
	}
}

/*�м���ʾ*/
static u8 _PassWordInput_MiddledDisplay (u8 *receive, u8 recSize, u8 xingflag, u8 DiplayRow, u8 argkeyval)
{
	u8 i;
	u8 inputSize;
	u8 displaybuff[22];
	u8 ClearFlag = 0;
	u8 keyval;

	inputSize = recSize > 21 ? 21 : recSize;
	memset (receive, 0, inputSize);
	i = 0;

	while (1)
	{
		if (argkeyval == KEY_NONE)
		{
			keyval = GetKeyValue();
		}
		else
		{
			keyval = argkeyval;
			argkeyval = KEY_NONE;
		}

		if (keyval == 0) continue;

		KeyEventPost();

		switch (keyval)
		{
			case KEY0:
				if (i < inputSize)
				{
					receive[i] = '0';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY1:
				if (i < inputSize)
				{
					receive[i] = '1';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY2:
				if (i < inputSize)
				{
					receive[i] = '2';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY3:
				if (i < inputSize)
				{
					receive[i] = '3';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY4:
				if (i < inputSize)
				{
					receive[i] = '4';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY5:
				if (i < inputSize)
				{
					receive[i] = '5';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY6:
				if (i < inputSize)
				{
					receive[i] = '6';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY7:
				if (i < inputSize)
				{
					receive[i] = '7';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY8:
				if (i < inputSize)
				{
					receive[i] = '8';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY9:
				if (i < inputSize)
				{
					receive[i] = '9';
					i++;
					receive[i] = 0;
				}

				break;

			case KEYXING:
				if (i < inputSize)
				{
					receive[i] = '.';
					i++;
					receive[i] = 0;
				}

				break;

			case KEY_DEL:
				if (i > 0)
				{
					i--;
					receive[i] = 0;
					ClearFlag = 1;
				}

				//else{KeyIsResponse();return KEY_ReturnPrevious;}
				break;

			case KEY_Enter:
				if (strlen ( (sc8*) receive) != 0)  	//��������ַ�Ϊ�գ����ð�ȷ�ϼ�����
				{
					KeyIsResponse();
					return KEY_Enter;
				}

				break;

			case KEY_ReturnPrevious:
				KeyIsResponse();
				return KEY_ReturnPrevious;

			case KEY_ReturnInitInterface:
			case KEY_WaitTimeout:
				KeyIsResponse();
				return KEY_ReturnInitInterface;
		}

		if (ClearFlag == 1)
		{
			ClearFlag = 0;
			clear_area_to_row (DiplayRow, DiplayRow);
		}

		if (xingflag)
		{
			memset (displaybuff, '*', i);
			displaybuff[i] = 0;
			DrawTitle_to_row (DiplayRow, displaybuff);
		}
		else
		{
			DrawTitle_to_row (DiplayRow, receive);
		}

		KeyIsResponse();
	}
}



//Ĭ����������Ϊ�����������ַ���ʾ�ڵڶ��С�
//��������Ϊ"����������"Input Password"�������밴��
//����buff Ϊ�β�2�������ֽ�Ϊ�β�3����*  ��ʾ������ַ�
void PassWordArgDeInit (PasswordInputArgument *arg, u8 *buff, u8 Size)
{
	(*arg).clearlcdflag = 1;
	(*arg).DiplayRow = 1;
	(*arg).LocalTitle = "����������";
	(*arg).OtherTitle = "Input Password";
	(*arg).keyval = KEY_NONE;
	(*arg).receive = buff;
	(*arg).recSize = Size;
	(*arg).xingflag = 1;
}

/*motice:Title��receive��recSize  max value is 20*/
u8 PassWordInput (PasswordInputArgument *arg)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_PassWordInput_XposStartDisplay ( (*arg).receive, (*arg).recSize, (*arg).xingflag, (*arg).DiplayRow, 0, (*arg).keyval) );
}


u8 PassWordInput_MiddledDisplay (PasswordInputArgument *arg)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_PassWordInput_MiddledDisplay ( (*arg).receive, (*arg).recSize, (*arg).xingflag, (*arg).DiplayRow, (*arg).keyval) );
}

u8 PassWordInput_XposStartDisplay (PasswordInputArgument *arg, u8 Xpos)
{
	if ( (*arg).clearlcdflag) clear_lcd();

	DrawTitle_to_row_Language2 (0, (*arg).LocalTitle, (*arg).OtherTitle);
	KeyIsResponse();

	return (_PassWordInput_XposStartDisplay ( (*arg).receive, (*arg).recSize, (*arg).xingflag, (*arg).DiplayRow, Xpos, (*arg).keyval) );
}


u8 PassWordInput2 (const u8 *Title, u8 *receive, u8 recSize, u8 xingflag, u8 clearlcdflag, u8 keyval, u8 DiplayRow)
{
	if (clearlcdflag) clear_lcd();

	if (Title != NULL) DrawTitle_to_row_Language2 (0, Title, Title);

	KeyIsResponse();

	return (_PassWordInput_XposStartDisplay (receive, recSize, xingflag, DiplayRow, 0, keyval) );
}


