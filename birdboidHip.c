
// birdboidHip.c (VEX for Attribute Wrangle)
// 各ポイントの近傍を探索し、簡易的なboid挙動を実装

float radius = 1.0; // 近傍探索半径
vector sep = {0,0,0};
vector ali = {0,0,0};
vector coh = {0,0,0};
int count = 0;

int handle = pcopen(0, "P", @P, radius, 10);
while (pciterate(handle))
{
	vector pos = pcimport(handle, "P");
	vector vel = pcimport(handle, "v");

	// Separation
	sep += normalize(@P - pos);

	// Alignment
	ali += vel;

	// Cohesion
	coh += pos;

	count += 1;
}
if (count > 0)
{
	ali /= count;
	coh = (coh/count) - @P;
}

// 各要素の重み
float sep_weight = 1.5;
float ali_weight = 1.0;
float coh_weight = 1.0;

// 新しい速度
vector newv = sep * sep_weight + ali * ali_weight + coh * coh_weight;
@v += newv * 0.05; // 速度に加算
@P += @v * @TimeInc; // 位置を更新
