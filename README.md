Informacija apie nuodojamas funkcijas.  
Įvedant duomenis apie studentą, pirmas duomuo yra vardas, antras pavardė, o visi kiti yra skaičiai - namų darbai, o pats paskutinis nuskaitomas kaip egzaminas, tuomet apsakaičiuojami galutiniai balai.
Galima rinktis, ar duomenis suvesti pačiam ar naudoti sugeneruotus failus arba net naujai generuoti failus. Norint spausdinti duomenis apie studento klasės objektą galima naudoti išvesties operatorių. Klasė turi destruktorių, bet kadangi naudojami vektoriai, int bei string reikšmės, kurios pačios tvarkosi su informacijos valymu, tai destruktorius neatlieka papildomų veiksmų.
---
**Paleidimo instrukcija:**<br>
1. Instaliuoti CMake. <br>
2. Instaliuoti Codeblocks ir pridėti kompiliatorio path į systemos aplinką. <br>
3. norint sukurti projektą atskirame folderyje, naudoti tokias eilutes : <br>
mkdir build <br>
cd build <br>
cmake -G "CodeBlocks - MinGW Makefiles" .. <br>
4. Atidarius projektą paspausti build. <br>
5. Paleisti .exe failą. <br>
6. Norint naujų sugeneruotų failų, atkomentuoti main.cpp esančias eilutes, o prireikus orginalių, kreiptis į mane per github. <br>
---
Kiekvienas relizas aprašytas prie pačio relizo, tai norint naudoti senesnes versijas, skaityti ten. <br>
---
**TESTAVIMAS** <br>
**CPU** - AMD Ryzen 5 5600H with Radeon Graphics 3.30 GHz. <br>
**RAM** - 16.0 GB DDR4.<br>
**SSD** - 1024 GB NVMe 3500 MB/s read, 3200 MB/s write. <br>

### Vektoriai (1)
| Duomenų skaičius |   1000 |  10000 | 100000 | 1000000 | 10000000 |
| ---------------- | ------ | ------ | ------- | -------- | --------- |
| Nuskaitymas      | 0.0032 | 0.0285 | 0.2782  | 2.8055   | 28.2362   |
| Išskirstymas     |   0    | 0.0034 | 0.0281  | 0.2561   |  3.1115   |
| Gerų rikiavimas  |   0    | 0.0053 | 0.0770  | 1.0020   | 12.3779   |
| Blogų rikiavimas |   0    | 0.0047 | 0.0714  | 0.9547   | 11.3096   |
| Gerų įrašymas    | 0.0029 | 0.0212 | 0.1947  | 1.9675   | 19.3429   |
| Blogų įrašymas   | 0.0018 | 0.0163 | 0.1676  | 1.6773   | 18.0931   |

### Sąrašai (1)
| Duomenų skaičius |   1000 |  10000 | 100000 | 1000000 | 10000000 |
| ---------------- | ------ | ------ | ------- | -------- | --------- |
| Nuskaitymas      | 0.0063 | 0.0300 | 0.2826  | 2.9587   | 28.9122   |
| Išskirstymas     |   0    | 0.0034 | 0.0341  | 0.3574   |  3.3732   |
| Gerų rikiavimas  |   0    | 0.0023 | 0.0348  | 0.5591   |  7.6788   |
| Blogų rikiavimas |   0    | 0.0024 | 0.0327  | 0.5177   |  7.2633   |
| Gerų įrašymas    | 0.0033 | 0.0219 | 0.2056  | 2.1298   | 20.6789   |
| Blogų įrašymas   | 0.0025 | 0.0174 | 0.1723  | 1.8015   | 18.9043   |
---
### Vektoriai (2)
| Duomenų skaičius |   1000 |  10000 | 100000 | 1000000 | 10000000 |
| ---------------- | ------ | ------ | ------- | -------- | --------- |
| Nuskaitymas      | 0.0028 | 0.0295 | 0.2746  | 2.7759   | 28.1835   |
| Išskirstymas     |   0    | 0.0020 | 0.0179  | 0.1840   |  1.8570   |
| Gerų rikiavimas  |   0    | 0.0044 | 0.0628  | 0.8121   | 10.0918   |
| Blogų rikiavimas |   0    | 0.0045 | 0.0686  | 0.8688   | 10.8007   |
| Gerų įrašymas    | 0.0024 | 0.0192 | 0.1841  | 1.8414   | 18.4071   |
| Blogų įrašymas   | 0.0019 | 0.0189 | 0.1759  | 1.8039   | 17.7931   |
| Suma             | 0.0071 | 0.0785 | 0.7840  | 8.2860   | 87.1332   |

### Sarašai (2)
| Duomenų skaičius |   1000 |  10000 | 100000 | 1000000 | 10000000 |
| ---------------- | ------ | ------ | ------- | -------- | --------- |
| Nuskaitymas      | 0.0033 | 0.0281 | 0.2734  | 2.8903   | 28.5774   |
| Išskirstymas     |   0    | 0.0010 | 0.0124  | 0.1250   |  1.2689   |
| Gerų rikiavimas  |   0    | 0.0013 | 0.0230  | 0.3855   |  5.7264   |
| Blogų rikiavimas |   0    | 0.0022 | 0.0265  | 0.4071   |  6.3899   |
| Gerų įrašymas    | 0.0024 | 0.0191 | 0.1853  | 1.9127   | 19.3189   |
| Blogų įrašymas   | 0.0025 | 0.0187 | 0.1784  | 1.9029   | 18.5518   |
| Suma             | 0.0082 | 0.0705 | 0.6990  | 7.6235   | 79.8333   |

### Vektoriai (2) % greitesni nei vektoriai (1)
|                 | 1000  | 10000 | 100000 | 1000000 | 10000000 |
| --------------- | ----- | ------| ------- | -------- | --------- |
| Nuskaitymas     | 13%   | -3%   | 1%      | 1%       | 0%        |
| Išskirstymas    |-      | 67%   | 58%     | 39%      | 68%       |
| Gerų rikiavimas | -     | 22%   | 23%     | 23%      | 23%       |
| Blogų rikiavimas|-      | 5%    | 4%      | 10%      | 5%        |
| Gerų įrašymas   | -     | 11%   | 6%      | 7%       | 5%        |
| Blogų įrašymas  | -     | -14%  | -5%     | -7%      | 2%        |
---
### Vektoriai (3)
| Duomenų skaičius |   1000 |  10000 | 100000 | 1000000 | 10000000 |
| ---------------- | ------ | ------ | ------- | -------- | --------- |
| Nuskaitymas      |   0    | 0.0315 | 0.2765  | 2.7333   | 27.8158   |
| Išskirstymas     |   0    |   0    |   0    | 0.1113   |  1.1107   |
| Gerų rikiavimas  |   0    | 0.0078 | 0.0629  | 0.8248   |  9.9307   |
| Blogų rikiavimas |   0    | 0.0079 | 0.0782  | 0.8809   | 10.5567   |
| Gerų įrašymas    |   0    | 0.0157 | 0.1775  | 1.8547   | 17.9698   |
| Blogų įrašymas   |   0    | 0.0219 | 0.1844  | 1.7872   | 17.5283   |
| Suma             |   0    | 0.0847 | 0.7794  | 8.1922   | 84.9121   |
---
### Vektoriai (3) % greitesni nei vektoriai (2)
|                 | 10000 | 100000 | 1000000 | 10000000 |
| --------------- | ----- | ------ | ------- | -------- |
| Nuskaitymas     |  -6%  |   -1%  |    2%   |    1%    |
| Išskirstymas    | -     | -      |   65%   |   67%    |
| Gerų rikiavimas | -44%  |    0%  |   -2%   |    2%    |
| Blogų rikiavimas| -43%  |  -12%  |   -1%   |    2%    |
| Gerų įrašymas   |  22%  |    4%  |   -1%   |    2%    |
| Blogų įrašymas  | -13%  |   -5%  |    1%   |    2%    |
| Suma            |  -7%  |    1%  |    1%   |    3%    |  
---
### Klases

|               | 1000        | 10000       | 100000      | 1000000      |
|---------------|-------------|-------------|-------------|--------------|
| Nuskaitymas    | 0.017112875 | 0.162097    | 1.6300375   | 16.321425    |
| Išskirstymas   | 0           | 0.001884925 | 0.0254015   | 0.236745     |
| Gerų rikiavimas| 0.0002502   | 0.007124575 | 0.11168575  | 1.3977475    |
| Blogų rikiavimas| 0.000751175 | 0.0083494   | 0.1159635   | 1.4818225    |
| Gerų įrašymas  | 0.00226045  | 0.020545775 | 0.19002875  | 1.91335      |
| blogų įrašymas | 0.002511925 | 0.018879825 | 0.1809385   | 1.8500075    |
| Suma          | 0.022886625 | 0.2188815   | 2.2540555   | 23.2010975   |
---
### Strukturos % greiciau nei klases. Lyginiami greičiai tarp "Klases" ir "Vektoriai (3)" lentelių.

|                  | 10000 | 100000 | 1000000 |
|------------------|-------|--------|---------|
| Nuskaitymas      | 379%  | 442%   | 455%    |
| Išskirstymas     | -     | -      | -6%     |
| Gerų rikiavimas  | -85%  | -62%   | -58%    |
| Blogų rikiavimas | -75%  | -67%   | -60%    |
| Gerų įrašymas    | 23%   | 7%     | -2%     |
| Blogų įrašymas   | -15%  | -2%    | 2%      |
| Suma             | 128%  | 148%   | 139%    |  
---
### Flagu greiciai
|                    | O1 Size 214KB |           | O2 Size 220KB |            | O3 Size 236KB |            |
|--------------------|---------------|-----------|:-------------:|:----------:|:-------------:|:----------:|
|                    | 100000        | 1000000   | 10000         | 100000     | 100000        | 1000000    |
| Nuskaitymas        | 0.162518      | 1.58791   | 0.167998      | 1.574875   | 0.156307      | 1.580305   |
| Išskirstymas       | 0.008513      | 0.089941  | 0.005001      | 0.0870811  | 0.012809      | 0.0879835  |
| Gerų rikiavimas    | 0.021796      | 0.287179  | 0.024751      | 0.304028   | 0.017814      | 0.318737   |
| Blogų rikiavimas   | 0.017803      | 0.324266  | 0.02281       | 0.3297605  | 0.030669      | 0.3207435  |
| Gerų įrašymas      | 0.183743      | 1.83334   | 0.181664      | 1.80463    | 0.171763      | 1.805285   |
| Blogų įrašymas     | 0.169567      | 1.793667  | 0.171548      | 1.792085   | 0.176815      | 1.778115   |
| Suma               | 0.56394       | 5.916302  | 0.573771      | 5.8924596  | 0.566176      | 5.891169   |

