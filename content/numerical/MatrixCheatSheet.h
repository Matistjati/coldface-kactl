/**
 * Author: Loke Gustafsson
 * Date: 2024-11-19
 * License: CC0
 * Description: \[
\begin{vmatrix}
a & b\\
c & d
\end{vmatrix}
=
ad - bc
\]
\[
\begin{bmatrix}
a & b\\
c & d
\end{bmatrix}^{-1}
=
\begin{vmatrix}
a & b\\
c & d
\end{vmatrix}^{-1}
\begin{bmatrix}
d & -b\\
-c & a
\end{bmatrix}
\]
\[
\begin{vmatrix}
a & b & c\\
d & e & f\\
g & h & i\\
\end{vmatrix}
=
aei + bfg + cdh - afh - bdi - ceg
\]
\[
\begin{bmatrix}
a & b & c\\
d & e & f\\
g & h & i\\
\end{bmatrix}^{-1}
=
\begin{vmatrix}
a & b & c\\
d & e & f\\
g & h & i\\
\end{vmatrix}^{-1}
\begin{bmatrix} 
e i - f h & c h - b i & b f - c e \\
f g - d i & a i - c g & c d - a f \\
d h - e g & b g - a h & a e - b d \\
\end{bmatrix}
\]

 */