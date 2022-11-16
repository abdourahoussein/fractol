# fractol

Découvrez la programmation 2D et l'univers psychédélique des fractales dans ce projet, en utilisant minilibX.
C'est quoi une fractale ?

Une figure fractale est un objet mathématique qui présente une structure similaire à toutes les échelles. C'est un objet géométrique « infiniment morcelé » dont des détails sont observables à une échelle arbitrairement choisie. En zoomant sur une partie de la figure, il est possible de retrouver toute la figure ; on dit alors qu’elle est « auto similaire ».

Dans ce projet j'ai créé trois figures fractales á savoir : **** L'ensemble de Mandelbrot: En mathématiques, l'ensemble de Mandelbrot est une fractale définie comme l'ensemble des points c du plan complexe pour lesquels la suite de nombres complexes définie par récurrence par Zn+1 = Zn * Zn + C. Plus de detail -> http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html

**** L'ensem de Julia: Soit c un nombre complexe. On considère la suite récurrente vérifiant Zn+1=(zn * zn) +c. L'ensemble de Julia associé à c est l'ensemble des points d'affixe z0 du plan pour lesquels cette suite ne tend pas, en module, vers l'infini. le nombre complexe c est une constate Contrairement á L'ensemble de Mandelbrot où est varie.

**** L'ensemble de Burning Ship: La fractale burning ship (« navire en feu », en anglais), décrite pour la première fois par Michael Michelitsch et Otto E. Rössler en 1992, elle a les mêmes propiétés que l'ensemble de Mandelbrot de la suite. ici Zn+1 = |(Zn * Zn)| + c.

make => ./fractal mandelbrot oubien ./fractal mandelbrot
make => ./bonus burning_ship.
Possible de se deplacer avec les flèches et de zoommer avec la sourie.
