# include <iostream>
# include <tpl_graph.H>		//incluye el tipo de dato List_Digraph
#include<tpl_graph_utils.H>	//incluye la clase Distance
#include<string>
#include <Dijkstra.H>		//very obvious
#include "new_node.h"      //para que el nodo contenga la latitud, longitud y nombre
#include <fstream>        // para poder exportar latitud y longitud a txt
using namespace std;

// Alias para el tipo de nodo y arco.
using Node = Graph_Node<new_node>;
using Arc = Graph_Arc<float>;


// Alias para el tipo de grafo
using GT = List_Digraph<Node,Arc>;


void print_graph(GT & g)
{
  // Imprime la cantidad de nodos del grafo
  cout << g.get_num_nodes() << " nodes\n";

  // Itera sobre el conjunto completo de nodos
  for (GT::Node_Iterator it(g); it.has_curr(); it.next())
    {
      auto p = it.get_curr();

      // Imprime la cantidad de arcos adyacentes a p
      cout << "Node " << p->get_info().name << ", "
	   << g.get_num_arcs(p) << " adjacent arcs: ";

      // Para el nodo que está visitando, itera sobre todos sus arcos adyacentes.
      for (GT::Node_Arc_Iterator ait(p); ait.has_curr(); ait.next())
	{
	  // Obtiene el nodo adyacente a p
	  auto q = ait.get_tgt_node();
	  cout << q->get_info().name << ' ';
	}

      cout << endl;
    }

 cout << endl << endl;

  // Imprime la cantidad total de arcos del grafo
  cout << g.get_num_arcs() << " arcs\n";

  // Itera sobre todos los arcos del grafo.
  for (GT::Arc_Iterator it(g); it.has_curr(); it.next())
    {
      auto a = it.get_curr();

      auto p = g.get_src_node(a);
      auto q = g.get_tgt_node(a);

      cout << p->get_info().name << " --> " << q->get_info().name << " con peso --> "<< a->get_info()<<endl;
    }
}

int main()
{
  GT graph, dijkstra_test; //por using es lo mismo que usar List_Digraph<Graph_Node<char>,GraphArc<Int>> graph;


//Ahora todos los nodos

	


	/*auto MR5A = graph.insert_node("Redoma 5 aguilas blancas");
	auto MCSF = graph.insert_node("calle San Francisco");
	auto MCSD0 = graph.insert_node("calle san diego A");
	auto MCSD1 = graph.insert_node("calle san diego B");
	auto MCSD2 = graph.insert_node("calle san diego C");
	auto MCSD3 = graph.insert_node("calle san diego D");
	auto MCACM = graph.insert_node("Cll la Aguada - Calle la Montaña");
	auto MCLA = graph.insert_node("Calle La Aguada");
	auto MACP = graph.insert_node("Calle la Aguada- Calle Pico Espejo");
	auto M1 = graph.insert_node("Calle 1");
	auto M1E = graph.insert_node("Calle 1 final");
	auto M2 = graph.insert_node("Calle 2");
	auto M2E = graph.insert_node("Calle 2 final");
	auto M3 = graph.insert_node("Calle Loma Redonda Esquina Cll. La Montaña");
	auto M4 = graph.insert_node("Cll. La Montaña - Cll. Loma Redonda");
	auto M5 = graph.insert_node("Cll. Nevados - Cll. Pico Espejo");
	auto M6 = graph.insert_node("Cll. 3 - Cll. Hoyada de Milla");
	auto M7 = graph.insert_node("Cll 3 Interseccion");
	auto M8 = graph.insert_node("Cll. 3 Final");
	auto M9 = graph.insert_node("Cll. 4 - Cll. 5");
	auto M10 = graph.insert_node("Calle 4");
	auto M11 = graph.insert_node("Calle 4 - Hoyada de Milla");
	auto M12 = graph.insert_node("Calle 5 - Hoyada de Milla");
	auto M13 = graph.insert_node("Calle 6 - Hoyada de Milla");
	auto M14 = graph.insert_node("Calle 7 - Hoyada de Milla");
	auto M15 = graph.insert_node("Antes de la redoma");
	auto M16 = graph.insert_node("Redoma de la avenida universidad");
	auto M17 = graph.insert_node("Calle 7 - Avenida Universidad");
	auto M18 = graph.insert_node("Calle 8 - Avenida Universidad");
	auto M19 = graph.insert_node("Interseccion Av. Universidad - La Milagrosa");
	auto M20 = graph.insert_node("Calle Los Nevados - Calle Yagrumo");
	auto M21 = graph.insert_node("Chorros - MIlagrosa");*/
	new_node node22(8.607188, -71.137845, "Enlace Charles Chaplin");
	auto M22 = graph.insert_node(node22);
	new_node node23(8.607933, -71.139876, "Enlace German Briceño");
	auto M23 = graph.insert_node(node23);
	new_node node24(8.604886, -71.141241, "Gran Mision Vivienda Venezuela Plaza Toros");
	auto M24 = graph.insert_node(node24);
	new_node node25(8.606880, -71.142357, "Plaza de Toros - Avda. Las Americas");
	auto M25 = graph.insert_node(node25);
	new_node node26(8.605822, -71.137827, "CLL 11 - AV 2");
	auto M26 = graph.insert_node(node26);
	new_node node27(8.606013, -71.138224, "CLL 11 - AV 1");
	auto M27 = graph.insert_node(node27);
	new_node node28(8.604655, -71.138074, "CLL 12 - AV 2");
	auto M28 = graph.insert_node(node28);
	new_node node29(8.605101, -71.138718, "CLL 12 - AV 1");
	auto M29 = graph.insert_node(node29);
	new_node node30(8.604390, -71.139255, "CLL 13 - AV 1");
	auto M30 = graph.insert_node(node30);
	new_node node31(8.603817, -71.138579, "CLL 13 - AV 2");
	auto M31 = graph.insert_node(node31);
	new_node node32(8.603095, -71.139394, "CLL 14 - AV 2");
	auto M32 = graph.insert_node(node32);
	new_node node33(8.603700, -71.140027, "CLL 14 - AV 1");
	auto M33 = graph.insert_node(node33);
	new_node node34(8.603159, -71.137978, "CLL 13 - AV 3");
	auto M34 = graph.insert_node(node34);
	new_node node35(8.602374, -71.138708, "CLL 14 - AV 3");
	auto M35 = graph.insert_node(node35);
	new_node node36(8.602427, -71.137281, "CLL 13 - AV 4");
	auto M36 = graph.insert_node(node36);
	new_node node37(8.601833, -71.136841, "CLL 14 - AV 4");
	auto M37 = graph.insert_node(node37);
	new_node node38(8.601727, -71.138075, "CLL 14 - AV 4");
	auto M38 = graph.insert_node(node38);
	new_node node39(8.601197, -71.137539, "CLL 14 - AV 5");
	auto M39 = graph.insert_node(node39);
	new_node node40(8.600518, -71.136863, "CLL 14 - AV 6");
	auto M40 = graph.insert_node(node40);
	new_node node41(8.603128, -71.140800, "CLL 15 - AV 1");
	auto M41 = graph.insert_node(node41);
	new_node node42(8.602428, -71.140167, "CLL 15 - AV 2");
	auto M42 = graph.insert_node(node42);
	new_node node43(8.601707, -71.139588, "CLL 15 - AV 3");
	auto M43 = graph.insert_node(node43);
	new_node node44(8.600996, -71.139019, "CLL 15 - AV 4");
	auto M44 = graph.insert_node(node44);
	new_node node45(8.600476, -71.138429, "CLL 15 - AV 5");
	auto M45 = graph.insert_node(node45);
	new_node node46(8.599797, -71.137753, "CLL 15 - AV 6");
	auto M46 = graph.insert_node(node46);
	new_node node47(8.599558, -71.137592, "CLL 15 - AV 7");
	auto M47 = graph.insert_node(node47);
	new_node node48(8.602592, -71.141411, "CLL 16 - AV 1");
	auto M48 = graph.insert_node(node48);
	new_node node49(8.601871, -71.140735, "CLL 16 - AV 2");
	auto M49 = graph.insert_node(node49);
	new_node node50(8.601181, -71.140231, "CLL 16 - AV 3");
	auto M50 = graph.insert_node(node50);
	new_node node51(8.600481, -71.139695, "CLL 16 - AV 4");
	auto M51 = graph.insert_node(node51);
	new_node node52(8.599887, -71.139169, "CLL 16 - AV 5");
	auto M52 = graph.insert_node(node52);
	new_node node53(8.599240, -71.138504, "CLL 16 - AV 6");
	auto M53 = graph.insert_node(node53);
	new_node node54(8.598847, -71.138075, "CLL 16 - AV 7");
	auto M54 = graph.insert_node(node54);
	new_node node55(8.598168, -71.137431, "CLL 16 - AV 8");
	auto M55 = graph.insert_node(node55);
	new_node node56(8.602051, -71.142066, "CLL 17 - AV 1");
	auto M56 = graph.insert_node(node56);
	new_node node57(8.601266, -71.141422, "CLL 17 - AV 2");
	auto M57 = graph.insert_node(node57);
	new_node node58(8.600608, -71.140907, "CLL 17 - AV 3");
	auto M58 = graph.insert_node(node58);
	new_node node59(8.599950, -71.140371, "CLL 17 - AV 4");
	auto M59 = graph.insert_node(node59);
	new_node node60(8.599271, -71.139867, "CLL 17 - AV 5");
	auto M60 = graph.insert_node(node60);
	new_node node61(8.598551, -71.138392, "CLL X1 - AV 7");
	auto M61 = graph.insert_node(node61);
	new_node node62(8.597819, -71.137748 "CLL X1 - AV 8");
	auto M62 = graph.insert_node(node62);
	new_node node63(8.598063, -71.138843, "CLL 17 - AV 7");
	auto M63 = graph.insert_node(node63);
	new_node node64(8.597437, -71.138231, "CLL 17 - AV 8");
	auto M64 = graph.insert_node(node64);
	//auto M65 = graph.insert_node("AV 8 - Pasaje Sanchez");
	new_node node66(8.597193, -71.137179, "Pasaje Sanchez - CLL X1");
	auto M66 = graph.insert_node(node66);
	new_node node67(8.596822, -71.137630, "CLL 17 - Pasaje Sanchez");
	auto M67 = graph.insert_node(node67);
	new_node node68(8.598604, -71.139261, "CLL 17 - AV 6");
	auto M68 = graph.insert_node(node68);
	new_node node69(8.597066, -71.138595, "CLL Y1 - AV 8");
	auto M69 = graph.insert_node(node69);
	new_node node70(8.596461, -71.138048, "CLL Y1 - Pasaje Sanchez");
	auto M70 = graph.insert_node(node70);
	new_node node71(8.601457, -71.142694, "CLL 18 - AV 1");
	auto M71 = graph.insert_node(node71);
	new_node node72(8.600757, -71.142125, "CLL 18 - AV 2");
	auto M72 = graph.insert_node(node72);
	new_node node73(8.600061, -71.141571, "CLL 18 - AV 3");
	auto M73 = graph.insert_node(node73);
	new_node node74(8.599403, -71.141080, "CLL 18 - AV 4");
	auto M74 = graph.insert_node(node74);
	new_node node75(8.598777, -71.140554, "CLL 18 - AV 5");
	auto M75 = graph.insert_node(node75);
	new_node node76(8.598087, -71.140028, "CLL 18 - AV 6");
	auto M76 = graph.insert_node(node76);
	new_node node77(8.597461, -71.139470, "CLL 18 - AV 7");
	auto M77 = graph.insert_node(node77);
	new_node node78(8.596846, -71.138976, "CLL 18 - AV 8");
	auto M78 = graph.insert_node(node78);
	new_node node79(8.600897, -71.143290, "CLL 19 - AV 1");
	auto M79 = graph.insert_node(node79);
	new_node node80(8.600218, -71.142786, "CLL 19 - AV 2");
	auto M80 = graph.insert_node(node80);
	new_node node81(8.599582, -71.142282, "CLL 19 - AV 3");
	auto M81 = graph.insert_node(node81);
	new_node node82(8.598861, -71.141756, "CLL 19 - AV 4");
	auto M82 = graph.insert_node(node82);
	new_node node83(8.598203, -71.141273, "CLL 19 - AV 5");
	auto M83 = graph.insert_node(node83);
	new_node node84(8.597567, -71.140704, "CLL 19 - AV 6");
	auto M84 = graph.insert_node(node84);
	new_node node85(8.596962, -71.140189, "CLL 19 - AV 7");
	auto M85 = graph.insert_node(node85);
	new_node node86(8.596241, -71.139706, "CLL 19 - AV 8");
	auto M86 = graph.insert_node(node86);
	new_node node87(8.596132, -71.138413, "CLL 18 - Pasaje Sanchez");
	auto M87 = graph.insert_node(node87);
	new_node node88(8.600191, -71.143812, "CLL 20 - AV 1");
	auto M88 = graph.insert_node(node88);
	new_node node89(8.599724, -71.143479, "CLL 20 - AV 2");
	auto M89 = graph.insert_node(node89);
	new_node node90(8.599088, -71.142964, "CLL 20 - AV 3");
	auto M90 = graph.insert_node(node90);
	new_node node91(8.598409, -71.142363, "CLL 20 - AV 4");
	auto M91 = graph.insert_node(node91);
	new_node node92(8.597751, -71.141934, "CLL 20 - AV 5");
	auto M92 = graph.insert_node(node92);
	new_node node93(8.597083, -71.141440, "CLL 20 - AV 6");
	auto M93 = graph.insert_node(node93);
	new_node node94(8.596383, -71.140914, "CLL 20 - AV 7");
	auto M94 = graph.insert_node(node94);
	new_node node95(8.595725, -71.140388, "CLL 20 - AV 8");
	auto M95 = graph.insert_node(node95);
	new_node node96(8.598538, -71.143600, "CLL 21 - AV 3");
	auto M96 = graph.insert_node(node96);
	new_node node97(8.597917, -71.143106, "CLL 21 - AV 4");
	auto M97 = graph.insert_node(node97);
	new_node node98(8.597227, -71.142559, "CLL 21 - AV 5");
	auto M98 = graph.insert_node(node98);
	new_node node99(8.596543, -71.142071, "CLL 21 - AV 6");
	auto M99 = graph.insert_node(node99);
	new_node node100(8.595853, -71.141556, "CLL 21 - AV 7");
	auto M100 = graph.insert_node(node100);
	new_node node101(8.595169, -71.141025, "CLL 21 - AV 8");
	auto M101 = graph.insert_node(node101);
	new_node node102(8.596686, -71.143246, "CLL 22 - AV 5");
	auto M102 = graph.insert_node(node102);
	new_node node103(8.596028, -71.142720, "CLL 22 - AV 6");
	auto M103 = graph.insert_node(node103);
	new_node node104(8.595370, -71.142189, "CLL 22 - AV 7");
	auto M104 = graph.insert_node(node104);
	new_node node105(8.594649, -71.141663, "CLL 22 - AV 8");
	auto M105 = graph.insert_node(node105);
	new_node node106(8.596856, -71.144442, "CLL 23 - AV 4");
	auto M106 = graph.insert_node(node106);
	new_node node107(8.596214, -71.143911, "CLL 23 - AV 5");
	auto M107 = graph.insert_node(node107);
	new_node node108(8.595535, -71.143385, "CLL 23 - AV 6");
	auto M108 = graph.insert_node(node108);
	new_node node109(8.594856, -71.142853, "CLL 23 - AV 7");
	auto M109 = graph.insert_node(node109);
	new_node node110(8.594182, -71.142311, "CLL 23 - AV 8");
	auto M110 = graph.insert_node(node110);
	new_node node110a(8.597030, -71.145605, "CLL 24 - AV 2");
	auto M110a = graph.insert_node(node110a);
	new_node node111(8.596346, -71.14510, "CLL 24 - AV 3");
	auto M111 = graph.insert_node(node111);
	new_node node112(8.596346, -71.14510, "CLL 24 - AV 4");
	auto M112 = graph.insert_node(node112);
	new_node node113(8.595699, -71.144570, "CLL 24 - AV 5");
	auto M113 = graph.insert_node(node113);
	new_node node114(8.595054, -71.144100, "CLL 24 - AV 6");
	auto M114 = graph.insert_node(node114);
	new_node node115(8.594380, -71.143553, "CLL 24 - AV 7");
	auto M115 = graph.insert_node(node115);
	new_node node116(8.593653, -71.142979, "CLL 24 - AV 8");
	auto M116 = graph.insert_node(node116);
	new_node node117(8.592757, -71.142169, "CLL 24 - ?av");
	auto M117 = graph.insert_node(node117);
	new_node node118(8.592237, -71.141627, "CLL 24 - CLL 25");
	auto M118 = graph.insert_node(node118);
	new_node node119(8.597150, -71.146756, "CLL 25 - AV 2");
	auto M119 = graph.insert_node(node119);
	new_node node120(8.596535, -71.146257, "CLL 25 - AV 3");
	auto M120 = graph.insert_node(node120);
	new_node node121(8.595863, -71.145738, "CLL 25 - AV 4");
	auto M121 = graph.insert_node(node121);
	new_node node122(8.595152, -71.14523, "CLL 25 - AV 5");
	auto M122 = graph.insert_node(node122);
	new_node node123(8.594542, -71.144762, "CLL 25 - AV 6");
	auto M123 = graph.insert_node(node123);
	new_node node124(8.593863, -71.144204, "CLL 25 - AV 7");
	auto M124 = graph.insert_node(node124);
	new_node node125(8.593102, -71.143644, "CLL 25 - AV 8");
	auto M125 = graph.insert_node(node125);
	new_node node126(8.592582, -71.143258, "CLL 25 - ?av");
	auto M126 = graph.insert_node(node126);
	new_node node127(8.592354, -71.143033, "CLL 25 - ?av1");
	auto M127 = graph.insert_node(node127);
	new_node node128(8.592799, -71.144036, "CLL Extra de la av 8 - AV  extra cerca del teleferico");
	auto M128 = graph.insert_node(node128);
	new_node node129(8.592348, -71.143677, "CLL Extra 2 de la av 8 - AV  extra cerca del teleferico");
	auto M129 = graph.insert_node(node129);
	new_node node130(8.592539, -71.144406, "CLL 26 - AV 8");
	auto M130 = graph.insert_node(node130);
	new_node node131(8.592587, -71.144353, "CLL ? - AV 8");
	auto M131 = graph.insert_node(node131);
	new_node node132(8.596710, -71.147340, "CLL 26 - AV 2");
	auto M132 = graph.insert_node(node132);
	new_node node133(8.596068, -71.146895, "CLL 26 - AV 3");
	auto M133 = graph.insert_node(node133);
	new_node node134(8.595352, -71.146369, "CLL 26 - AV 4");
	auto M134 = graph.insert_node(node134);
	new_node node135(8.594689, -71.145843, "CLL 26 - AV 5");
	auto M135 = graph.insert_node(node135);
	new_node node136(8.594042, -71.145425, "CLL 26 - AV 6");
	auto M136 = graph.insert_node(node136);
	new_node node137(8.593310, -71.144958, "CLL 26 - AV 7");
	auto M137 = graph.insert_node(node137);
	new_node node138(8.596136, -71.148201, "CLL 27 - AV 2");
	auto M138 = graph.insert_node(node138);
	new_node node139(8.595468, -71.147643, "CLL 27 - AV 3");
	auto M139 = graph.insert_node(node139);
	new_node node140(8.594853, -71.147042, "CLL 27 - AV 4");
	auto M140 = graph.insert_node(node140);
	new_node node141(8.595585, -71.148844, "CLL 28 - AV 2");
	auto M141 = graph.insert_node(node141);
	new_node node142(8.594959, -71.148308, "CLL 28 - AV 3");
	auto M142 = graph.insert_node(node142);
	new_node node143(8.594286, -71.147799, "CLL 28 - AV 4");
	auto M143 = graph.insert_node(node143);
	new_node node144(8.595092, -71.149408, "CLL 29 - AV 2");
	auto M144 = graph.insert_node(node144);
	new_node node145(8.594434, -71.148925, "CLL 29 - AV 3");
	auto M145 = graph.insert_node(node145);
	new_node node146(8.593797, -71.148421, "CLL 29 - AV 4");
	auto M146 = graph.insert_node(node146);
	new_node node147(8.594550, -71.150095, "CLL 30 - AV 2");
	auto M147 = graph.insert_node(node147);
	new_node node148(8.593850, -71.149516, "CLL 30 - AV 3");
	auto M148 = graph.insert_node(node148);
	new_node node149(8.593341, -71.149022, "CLL 30 - AV 4");
	auto M149 = graph.insert_node(node149);
	new_node node150(8.593966, -71.150729, "CLL 31 - AV 2");
	auto M150 = graph.insert_node(node150);
	new_node node151(8.593372, -71.150189, "CLL 31 - AV 3");
	auto M151 = graph.insert_node(node151);
	new_node node152(8.592810, -71.149685, "CLL 31 - AV 4");
	auto M152 = graph.insert_node(node152);
	new_node node153(8.593457, -71.151359, "CLL 32 - AV 2");
	auto M153 = graph.insert_node(node153);
	new_node node154(8.592863, -71.150865, "CLL 32 - AV 3");
	auto M154 = graph.insert_node(node154);
	new_node node155(8.592280, -71.150339, "CLL 32 - AV 4");
	auto M155 = graph.insert_node(node155);
	new_node node156(8.592938, -71.152056, "CLL 33 - AV 2");
	auto M156 = graph.insert_node(node156);
	new_node node157(8.592397, -71.151595, "CLL 33 - AV 3");
	auto M157 = graph.insert_node(node157);
	new_node node158(8.591782, -71.151101, "CLL 33 - AV 4");
	auto M158 = graph.insert_node(node158);
	new_node node159(8.592472, -71.152667, "CLL 34 - AV 2");
	auto M159 = graph.insert_node(node159);
	new_node node160(8.591899, -71.152238, "CLL 34 - AV 3");
	auto M160 = graph.insert_node(node160);
	new_node node161(8.591284, -71.151734, "CLL 34 - AV 4");
	auto M161 = graph.insert_node(node161);
	new_node node162(8.591921, -71.153354, "CLL 35 - AV 2");
	auto M162 = graph.insert_node(node162);
	new_node node163(8.591401, -71.152936, "CLL 35 - AV 3");
	auto M163 = graph.insert_node(node163);
	new_node node164(8.590733, -71.152432, "CLL 35 - AV 4");
	auto M164 = graph.insert_node(node164);
	new_node node165(8.591370, -71.153998, "CLL 36 - AV 2");
	auto M165 = graph.insert_node(node165);
	new_node node166(8.590871, -71.153569, "CLL 36 - AV 3");
	auto M166 = graph.insert_node(node166);
	new_node node167(8.590224, -71.153065, "CLL 36 - AV 4");
	auto M167 = graph.insert_node(node167);
	new_node node167a(8.589853, -71.152797, "CLL 36 - AV Gonzalo Picón");
	auto M167a = graph.insert_node(node167a);
	new_node node168(8.590840, -71.154632, "CLL 37 - AV 2");
	auto M168 = graph.insert_node(node168);
	new_node node169(8.590384, -71.154246, "CLL 37 - AV 3");
	auto M169 = graph.insert_node(node169);
	new_node node170(8.589419, -71.153484, "CLL 37 - AV Gonzalo Picón");
	auto M170 = graph.insert_node(node170);
	new_node node170a(8.589494, -71.153173, "CLL B6A - AV Gonzalo Picón");
	auto M170a = graph.insert_node(node170a);
	new_node node170b(8.589027, -71.153473, "CLL X1 - AV Gonzalo Picón");
	auto M170b = graph.insert_node(node170b);
	new_node node170c(8.588698, -71.153891, "CLL X2 - AV Gonzalo Picón");
	auto M170c = graph.insert_node(node170c);
	new_node node170d(8.588380, -71.154288, "CLL X3 - AV Gonzalo Picón");
	auto M170d = graph.insert_node(node170d);
	new_node node171(8.589673, -71.156070, "CLL 38 - AV 2");
	auto M171 = graph.insert_node(node171);
	new_node node172(8.589111, -71.155619, "CLL 38 - AV 3");
	auto M172 = graph.insert_node(node172);
	new_node node173(8.588210, -71.154761, "CLL 38 - AV Gonzalo Picón");
	auto M173 = graph.insert_node(node173);
	

	/*auto M153 = graph.insert_node("Milagrosa - Chorros 2");
	auto M154 = graph.insert_node("Chorros - Geografia");
	auto M155 = graph.insert_node("Amparo - Chorros - Forestal");
	auto M156 = graph.insert_node("Chorros - pasaje 1 Chorros");
	auto M157 = graph.insert_node("Chorros - pasaje 2 Chorros");
	auto M158 = graph.insert_node("Chorros - Forestal - Tia Mila");
	auto M158a = graph.insert_node("Ciclo Basico");
	auto M159 = graph.insert_node("Dentro de forestales");
	auto M160 = graph.insert_node("CEFAP");
	auto M161 = graph.insert_node("Chorros - Pasaje Quintero");
	auto M162 = graph.insert_node("Chorros - Calle 1 Chorros");
	auto M163 = graph.insert_node("Chorros - Mas arriba calle 1 Chorros");
	auto M164 = graph.insert_node("Chorros -  Cll. EL Conuco");
	auto M165 = graph.insert_node("Enlace Chorros - Hechicera");
	auto M166 = graph.insert_node("Redoma de los chorros - Zoologico");
	auto M167 = graph.insert_node("Chorros Calles 1 2 y 3");
	auto M168 = graph.insert_node("Autolavado - Recta Hechicera - San Pedro");
	auto M169 = graph.insert_node("Primera entrada Ingenieria");
	auto M170 = graph.insert_node("Parada de BIACI");
	auto M171 = graph.insert_node("Arquitectura");
	auto M172 = graph.insert_node("Entrada Sta. Rosa");
	auto M173 = graph.insert_node("Otra entrada Deportes");
	auto M174 = graph.insert_node("Estadio Bajando - Recta Hechicera");
	auto aux1 = graph.insert_node("Hechicera - Nodo Auxiliar");
	auto M175 = graph.insert_node("Bifurcacion");
	auto M176 = graph.insert_node("Conjunto Residencial la Hechicera 1");
	auto M177 = graph.insert_node("CC la Hechicera");
	auto M178 = graph.insert_node("Conjunto Residencial la Hechicera 2");
	auto M179 = graph.insert_node("Entrada sta. Ana");
	auto M180 = graph.insert_node("La Escena Bar");
	auto M181 = graph.insert_node("Jardin Botanico");
	auto M182 = graph.insert_node("Estacion de Servicio la Hechicera");
	auto M183 = graph.insert_node("Mukumbarila");
	auto M184 = graph.insert_node("Av Universidad -  Calle Yagrumo");
	auto M185 = graph.insert_node("Av Universidad - El Bosque");
	auto M186 = graph.insert_node("El Amparo");
	auto M186a = graph.insert_node("Av Universidad - Chorros");
	auto M187 = graph.insert_node("El Amparo - El Bosque");
	auto M188 = graph.insert_node("El Bosque");
	auto M189 = graph.insert_node("Albarregas 1");
	auto M190 = graph.insert_node("Albarregas 2");

*/

// auto nombre = GT.insert_node('value');

//GT.insert_arc(src,target,weight)

//Ahora todos los Arcos

  graph.insert_arc(M1E,M1,144.75);
  graph.insert_arc(M1,M1E,144.75);
  graph.insert_arc(M1,M2,40.92);
  graph.insert_arc(M2,M1,40.92);
  graph.insert_arc(M2,M2E,179.01);
  graph.insert_arc(M2,MR5A,43.2);
  graph.insert_arc(M2E,M2,179.01);
  graph.insert_arc(MR5A,M2,43.2);
  graph.insert_arc(MR5A,MCSF,156.25);
  graph.insert_arc(MR5A,M185,616.64);
  graph.insert_arc(MCSF,MR5A,156.25);
  graph.insert_arc(MCSF,MCSD0,52.15);
  graph.insert_arc(MCSD0,MCSF,52.15);
  graph.insert_arc(MCSD0,MCSD1,78.42);
  graph.insert_arc(MCSD1,MCSD2,110.76);
  graph.insert_arc(MCSD2,MCSD3,69.52);
  graph.insert_arc(MCSD3,MCSD0,104.92);
  graph.insert_arc(M185,M186a,202.82);
  graph.insert_arc(M185,M188,46.03);
  graph.insert_arc(M186a,M21,110.48);
  graph.insert_arc(M186a,M19,53.32);
  graph.insert_arc(M188,M185,46.03);
  graph.insert_arc(M188,M187,48.08);
  graph.insert_arc(M19,M184,460.11);
  graph.insert_arc(M19,M21,99.97);
  graph.insert_arc(M19,M16,718.74);
  graph.insert_arc(M184,MR5A,404.99);
  graph.insert_arc(M187,M188,48.08);
  graph.insert_arc(M187,M186,164.38);
  graph.insert_arc(M186,M187,164.38);
  graph.insert_arc(M186,M155,161.44);
  graph.insert_arc(M155,M186,161.44);
  graph.insert_arc(M155,M154,118.39);
  graph.insert_arc(M155,M159,162);
  graph.insert_arc(M155,M156,464.47);
  graph.insert_arc(M21,M154,279.46);
  graph.insert_arc(M21,M153,163.8);
  graph.insert_arc(M153,M182,870.65);
  graph.insert_arc(M158a,M153,182.56);
  graph.insert_arc(M154,M158a,75.13);
  graph.insert_arc(M154,M155,118.39);
  graph.insert_arc(M156,M155,484.47);
  graph.insert_arc(M156,M157,48.61);
  graph.insert_arc(M157,M156,48.61);
  graph.insert_arc(M157,M158,238);
  graph.insert_arc(M158,M157,238);
  graph.insert_arc(M158,M160,427.5);
  graph.insert_arc(M158,M161,176.08);
  graph.insert_arc(M159,M155,162);
  graph.insert_arc(M159,M160,307.4);
  graph.insert_arc(M160,M159,307.4);
  graph.insert_arc(M160,M158,427.5);
  graph.insert_arc(M154,M155,118.39);
  graph.insert_arc(M161,M158,176.08);
  graph.insert_arc(M161,M162,59.63);
  graph.insert_arc(M162,M163,54.45);
  graph.insert_arc(M162,M161,59.63);
  graph.insert_arc(M163,M164,95.49);
  graph.insert_arc(M163,M162,54.45);
  graph.insert_arc(M164,M165,228.48);
  graph.insert_arc(M164,M163,95.49);
  graph.insert_arc(M165,M167,203.23);
  graph.insert_arc(M165,M168,252.12);
  graph.insert_arc(M167,M165,42.19);
  graph.insert_arc(M167,M166,202.23);
  graph.insert_arc(M166,M167,42.19);
  graph.insert_arc(M168,M165,252.12);
  graph.insert_arc(M168,M175,372.93);
  graph.insert_arc(M168,aux1,100.49);
  graph.insert_arc(aux1,M175,103.6);
  graph.insert_arc(aux1,M169,290.53);
  graph.insert_arc(aux1,M168,100.49);
  graph.insert_arc(M175,aux1,103.6);
  graph.insert_arc(M175,M168,372.93);
  graph.insert_arc(M175,M174,379.01);



  //print_graph(graph);

  Aleph::Dijkstra_Min_Paths<GT> dijkstra; //Creo una variable donde se encuentra el algoritmo dijkstra
  dijkstra(graph,M1, dijkstra_test); //Ejecuto el codigo dijkstra para el grafo "graph", empezando en M1 y guardando el arbol abarcados en el dijkstra_test
  print_graph(dijkstra_test); //imprimo el arbol abarcador

	void export_info(){  //para pasar latitud y longitud de cada nodo a un archivo de texto
  		ofstream write_info ("node_info.txt" );  //creo el archivo de texto
  			//incluyo latitud y longitud en el txt iterando sobre cada nodo
			for (Graph::Node_Iterator ait(grafo); ait.has_curr(); ait.next()){
  				write_info <<"Latitude: " <<ait.get_curr()->get_info().latitude << ", Longitude: " << ait.get_curr()->get_info().longitud << endl;
  			}
		write_info.close();
	}
  
  return 0;
}
