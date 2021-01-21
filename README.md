# GameOfLife

c++ simulator of <a href='https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life'>Conway's Game of Life</a>, a cellular simulation.

<h1>How to Play</h1>
Activate (click on) the cells that will begin the simulation as living cells. Black cells represent active (living) cells, white cells represent inactive (dead) cells. Press the space bar to see the next generation of cells. One space bar click = one generation. 


<h3>Rules</h3>
<ol>A live cell with exactly three live neighbors will survive to the next round</ol>
<ol>A live cell with less than two live neighbors will die of underpopulation</ol>
<ol>A live cell with more than three live neighbors will die of overpopulation</ol>
<ol>An inactive cell with three live neighbors will come to life through repopulation</ol>
