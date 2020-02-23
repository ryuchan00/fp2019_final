# fp2019_final
FP2019の最終課題

## 学内ネットワークに対してこのコードをコピーする方法

初回は以下を実行することで、コードをコピーできる。fp2019_finalというフォルダができる。

```
ssh [学籍番号]@sol.edu.cc.uec.ac.jp
git clone https://github.com/ryuchan00/fp2019_final.git
```

更新分を反映するには以下を実行する

```
cd fp2019_final
git pull
```
## gifファイルの作成方法

```
gcc animate1.c img.c -lm
./a.out
convert -delay 5 img/img*.ppm img/anim.gif
```
