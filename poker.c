#include <stdio.h>

int main(){
  int card[5] = {9,11,10,13,12};

  int tmp;
  int i,p,q;

  //配列の中身を昇順にソート
  for (p=0; p<4; p++){
    for (q=p+1; q<5; q++){

      if (card[p] > card[q]){
        tmp = card[q];
        card[q] = card[p];
        card[p] = tmp;
      }
    }
  }

  //「1〜13」より範囲外の数字を除外
  for (i=0; i<5; i++){
    printf("%d ",card[i]);

    if (card[i]<1 || card[i]>13 ){
      printf("\n1〜13の間で数字を入力して下さい\n");
      return 0;
    }
  }
  printf("\n\n");

  int r=0;
  for (p=0; p<4; p++){
    for (q=p+1; q<5; q++){

      if (card[p] == card[q]){
        r++;

      }
    }
  }

  if (r==1){
    printf("１ペアです！\n");

  } else if (r==2){
    printf("2ペアです！\n");

  } else if (r==3){
    printf("3カードです！\n");

  } else if (r==4){
    printf("フルハウスです！\n");

  } else if (r==6){
    printf("4カードです！\n");

  } else if (r==0){
    printf("ストレートです！\n");
  }






}
