# Նախագիծ․ so_long

## 📌 Նպատակ
Ստեղծել պարզ 2D խաղ, օգտագործելով MiniLibX գրադարանը, որտեղ խաղացողը պետք է հավաքի բոլոր հավաքելիները և հասնի ելքին։

## 🎮 Խաղի կանոնները
- Խաղացողը կառավարում է W, A, S, D կոճակներով։
- Նպատակն է հավաքել բոլոր `C`-ները և հասնել `E` ելքին։
- Խաղացողը չի կարող անցնել պատերի միջով (`1`)։
- Յուրաքանչյուր քայլից հետո տերմինալում երևում է քայլերի քանակը։
- Քարտեզը վերցվում է `.ber` ֆայլից։

## 🧱 Քարտեզի տարրերը
Քարտեզում օգտագործվում են հետևյալ նշանները՝
- `0` — դատարկ տարածք
- `1` — պատ
- `C` — հավաքելիներ
- `E` — ելք
- `P` — խաղացողի մեկնարկային դիրք

## 🖼️ Գրաֆիկա
- Օգտագործվում է MiniLibX
- Խաղի պատուհանը բացվում և փակվում է ESC կամ պատուհանի փակման կոճակով
- Յուրաքանչյուր քայլին պատկերը թարմացվում է
