echo "remember to give correct i_prev"
i_prev=9
#for i in 8161 8162 8163 8164 8166 8167 8168 8169 8171 8172 8173 8174 8176 8177 8178 8179; do
for i in {0..9}; do
  sed -i "s/i_set=$i_prev/i_set=$i/g" round_cond_cooling_calc_many.C
  root -q round_cond_cooling_calc_many.C
  i_prev=$i
done


#81631 81731 81681 81781 81903 8183
