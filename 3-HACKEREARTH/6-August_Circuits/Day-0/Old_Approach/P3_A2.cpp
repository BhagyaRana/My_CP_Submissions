#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
typedef unsigned long long int ull;

#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here

// All Variables Here

int main()
{
    b_v_r();

    ull k;
    cin >> k;
    if (k <= 200)
    {
        ull n = 1 + k;
        ull m = 1 + (k - 1) * 2;
        cout << n << " " << m << endl;

        cout << 1 << " " << n << endl;

        ull tmp = 2;
        for (ll i = 1; i <= (k - 1); i++)
        {
            cout << 1 << " " << tmp << endl;
            cout << tmp << " " << n << endl;
            tmp++;
        }
    }
    else
    {
        if (k != 1000000000000000000)
            cout << "-1" << endl;
        else
        {
            cout << "202 283\n1 2\n2 3\n2 4\n3 5\n4 5\n1 179\n179 5\n5 6\n5 7\n6 8\n7 8\n8 9\n8 10\n9 11\n10 11\n1 180\n180 11\n11 12\n11 13\n12 14\n13 14\n1 181\n181 14\n14 15\n14 16\n15 17\n16 17\n1 182\n182 17\n17 18\n17 19\n18 20\n19 20\n1 183\n183 20\n20 21\n20 22\n21 23\n22 23\n23 24\n23 25\n24 26\n25 26\n26 27\n26 28\n27 29\n28 29\n29 30\n29 31\n30 32\n31 32\n32 33\n32 34\n33 35\n34 35\n35 36\n35 37\n36 38\n37 38\n1 184\n184 38\n38 39\n38 40\n39 41\n40 41\n41 42\n41 43\n42 44\n43 44\n1 185\n185 44\n44 45\n44 46\n45 47\n46 47\n1 186\n186 47\n47 48\n47 49\n48 50\n49 50\n50 51\n50 52\n51 53\n52 53\n1 187\n187 53\n53 54\n53 55\n54 56\n55 56\n1 188\n188 56\n56 57\n56 58\n57 59\n58 59\n59 60\n59 61\n60 62\n61 62\n1 189\n189 62\n62 63\n62 64\n63 65\n64 65\n65 66\n65 67\n66 68\n67 68\n1 190\n190 68\n68 69\n68 70\n69 71\n70 71\n1 191\n191 71\n71 72\n71 73\n72 74\n73 74\n74 75\n74 76\n75 77\n76 77\n77 78\n77 79\n78 80\n79 80\n1 192\n192 80\n80 81\n80 82\n81 83\n82 83\n1 193\n193 83\n83 84\n83 85\n84 86\n85 86\n1 194\n194 86\n86 87\n86 88\n87 89\n88 89\n89 90\n89 91\n90 92\n91 92\n1 195\n195 92\n92 93\n92 94\n93 95\n94 95\n95 96\n95 97\n96 98\n97 98\n98 99\n98 100\n99 101\n100 101\n1 196\n196 101\n101 102\n101 103\n102 104\n103 104\n1 197\n197 104\n104 105\n104 106\n105 107\n106 107\n1 198\n198 107\n107 108\n107 109\n108 110\n109 110\n110 111\n110 112\n111 113\n112 113\n1 199\n199 113\n113 114\n113 115\n114 116\n115 116\n1 200\n200 116\n116 117\n116 118\n117 119\n118 119\n119 120\n119 121\n120 122\n121 122\n122 123\n122 124\n123 125\n124 125\n1 201\n201 125\n125 126\n125 127\n126 128\n127 128\n128 129\n128 130\n129 131\n130 131\n131 132\n131 133\n132 134\n133 134\n134 135\n134 136\n135 137\n136 137\n137 138\n137 139\n138 140\n139 140\n140 141\n140 142\n141 143\n142 143\n143 144\n143 145\n144 146\n145 146\n146 147\n146 148\n147 149\n148 149\n149 150\n149 151\n150 152\n151 152\n152 153\n152 154\n153 155\n154 155\n155 156\n155 157\n156 158\n157 158\n158 159\n158 160\n159 161\n160 161\n161 162\n161 163\n162 164\n163 164\n164 165\n164 166\n165 167\n166 167\n167 168\n167 169\n168 170\n169 170\n170 171\n170 172\n171 173\n172 173\n173 174\n173 175\n174 176\n175 176\n176 177\n176 178\n177 202\n178 202\n";
        }
    }

    return 0;
}