echo "remember to give correct i_prev"
i_prev=8162
for i in 8161 8162 8163 8164 8166 8167 8168 8169 8171 8172 8173 8174 8176 8177 8178 8179; do
#for i in {58..65}; do
  sed -i "s/i_und=$i_prev/i_und=$i/g" track_part_hel_und.C
  sed -i "s/op3_cur=248/op3_cur=401/g" track_part_hel_und.C
  root -q track_part_hel_und.C
  i_prev=$i
done


#81631 81731 81681 81781 81903 8183
