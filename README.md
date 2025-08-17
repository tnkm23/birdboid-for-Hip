# birdboid-for-Hip
birdboid for Houdini

# 使い方

/obj で Geometry 作成 → 中に

Attribute Wrangle (Init) … 1フレーム目だけ初期化

Solver SOP（中に Attribute Wrangle (BoidsSim) を入れる）
という構成にします。
※Solver が毎フレーム状態（@P,v@vel）を保持します。

Init を「Detail (only once)」実行に設定し、下の「Init用 VEX」を貼り付け。

Solver の中の BoidsSim を「Run Over: Points」にして、下の「シミュレーション VEX」を貼り付け。
パラメータ（半径・係数・視野など）を Wrangle UI から調整します。

2D で始めたい場合は Z を固定（@P.z = 0;）すると、元コードに近い挙動になります。