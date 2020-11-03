 
�� # i n c l u d e   < i o s t r e a m > 
 # i n c l u d e   < t i m e . h > 
 
 u s i n g   n a m e s p a c e   s t d ; 
 
 c l a s s   G u n   { 
 p u b l i c : 
         f l o a t   a t a c k S p e e d ; 
         f l o a t   a t a c k P o w e r ; 
         f l o a t   o n R e f r e s h   =   0 ; 
 } ; 
 
 c l a s s   S w o r d   { 
 p u b l i c : 
         f l o a t   a t a c k S p e e d ; 
         f l o a t   a t a c k P o w e r ; 
         f l o a t   o n R e f r e s h   =   0 ; 
 } ; 
 
 c l a s s   E n t i t y   { 
 p u b l i c : 
         f l o a t   h e a l t h ; 
         f l o a t   r e g e n e r a t i o n   =   0 ; 
         f l o a t   a t a c k P o w e r ; 
         E n t i t y ( )   { 
                 h e a l t h   =   1 0   +   r a n d ( )   %   3 1 ; 
                 a t a c k P o w e r   =   R a n d o m i z e ( ) ; 
         } 
         E n t i t y ( f l o a t   h e a l t h ,   f l o a t   a t a c k P o w e r ,   f l o a t   r e g e n e r a t i o n )   { 
                 t h i s - > h e a l t h   =   h e a l t h ; 
                 t h i s - > a t a c k P o w e r   =   a t a c k P o w e r ; 
                 t h i s - > r e g e n e r a t i o n   =   r e g e n e r a t i o n ; 
         } 
 
         v o i d   P r i n t H e a l t h ( )   { 
                 i f   ( h e a l t h   > =   0 )   { 
                         c o u t   < <   h e a l t h   < <   e n d l ; 
                 } 
                 e l s e   { 
                         c o u t   < <   0   < <   e n d l ; 
                 } 
         } 
 p r i v a t e : 
         f l o a t   R a n d o m i z e ( )   { 
                 r e t u r n   1   +   ( r a n d ( )   %   1 0 )   /   1 0   +   r a n d ( )   %   2 0 ; 
         } 
 } ; 
 
 v o i d   A t a c k ( E n t i t y *   p l a y e r ,   E n t i t y *   e n e m y ,   S w o r d *   s w o r d ,   G u n *   g u n ,   i n t   q u a n t i t y G u n ) ; 
 v o i d   P r i n t H e a l t h ( E n t i t y *   p l a y e r ,   E n t i t y *   e n e m y ) ; 
 i n t   m a i n ( ) 
 { 
         s r a n d ( t i m e ( 0 ) ) ; 
         i n t   q u a n t i t y E n e m y   =   1 0 ; 
         E n t i t y *   e n e m y   =   n e w   E n t i t y [ q u a n t i t y E n e m y ] ; 
 
         E n t i t y   p l a y e r   =   E n t i t y ( 1 0 0 ,   1 ,   0 . 4 f ) ; 
 
         i n t   q u a n t i t y G u n   =   3 ; 
         G u n *   g u n s   =   n e w   G u n [ q u a n t i t y G u n ] ; 
         S w o r d   s w o r d ; 
 
         f o r   ( i n t   i   =   0 ;   i   <   q u a n t i t y E n e m y ;   i + + )   { 
                 e n e m y [ i ]   =   E n t i t y ( ) ; 
                 
         } 
 
         f o r   ( i n t   i   =   0 ;   i   <   q u a n t i t y G u n ;   i + + )   { 
                 g u n s [ i ] . a t a c k P o w e r   =   3   +   r a n d ( )   %   1 3 ; 
                 g u n s [ i ] . a t a c k S p e e d   =   ( i n t ) g u n s [ i ] . a t a c k P o w e r   %   3   +   r a n d ( )   %   1 1   /   1 0 ; 
         } 
 
         s w o r d . a t a c k P o w e r   =   2 0 ; 
         s w o r d . a t a c k S p e e d   =   2 ; 
 
         f o r   ( i n t   i   =   0 ;   i   <   q u a n t i t y E n e m y ;   i + + )   { 
                 w h i l e   ( e n e m y [ i ] . h e a l t h   > =   0 )   { 
                         A t a c k ( & p l a y e r ,   & e n e m y [ i ] ,   & s w o r d ,   g u n s ,   q u a n t i t y G u n ) ; 
                         i f   ( p l a y e r . h e a l t h   < =   0 )   b r e a k ; 
                 } 
                 i f   ( p l a y e r . h e a l t h   < =   0 )   { 
                         c o u t   < <   e n d l   < <   " Y o u   a r e   l o s e ! "   < <   e n d l ; 
                         b r e a k ; 
                 } 
         } 
 
         i f   ( p l a y e r . h e a l t h   >   0 )   { 
                 c o u t   < <   e n d l   < <   " Y o u   a r e   w i n ! "   < <   e n d l ; 
         } 
 } 
 
 v o i d   A t a c k ( E n t i t y *   p l a y e r ,   E n t i t y *   e n e m y ,   S w o r d *   s w o r d ,   G u n *   g u n ,   i n t   q u a n t i t y G u n )   { 
         f l o a t   a p m   =   0 ; 
         i f   ( s w o r d - > o n R e f r e s h   < =   0 )   { 
                 e n e m y - > h e a l t h   - =   p l a y e r - > a t a c k P o w e r   *   s w o r d - > a t a c k P o w e r ; 
                 
                 a p m   + =   p l a y e r - > a t a c k P o w e r   *   s w o r d - > a t a c k P o w e r ; 
                 s w o r d - > o n R e f r e s h   =   s w o r d - > a t a c k S p e e d ; 
         } 
         e l s e   { 
                 s w o r d - > o n R e f r e s h   - =   1 ; 
                 f o r   ( i n t   i   =   0 ;   i   <   q u a n t i t y G u n ;   i + + )   { 
                         i f   ( g u n [ i ] . o n R e f r e s h   < =   0 )   { 
                                 e n e m y - > h e a l t h   - =   g u n [ i ] . a t a c k P o w e r ; 
                                 g u n [ i ] . o n R e f r e s h   =   g u n [ i ] . a t a c k S p e e d ; 
                                 a p m   + =   g u n [ i ] . a t a c k P o w e r ; 
                                 b r e a k ; 
                         } 
                         e l s e   { 
                                 g u n [ i ] . o n R e f r e s h   - =   1 ; 
                         } 
                 } 
         } 
         i f ( e n e m y - > h e a l t h   >   0 )   p l a y e r - > h e a l t h   - =   e n e m y - > a t a c k P o w e r ; 
         p l a y e r - > h e a l t h   + =   p l a y e r - > r e g e n e r a t i o n ; 
         
         c o u t   < <   e n d l   < <   " P l a y e r   h e a l t h :   " ; 
         p l a y e r - > P r i n t H e a l t h ( ) ; 
 
         c o u t   < <   e n d l   < <   " E n e m y   h e a l t h :   " ; 
         e n e m y - > P r i n t H e a l t h ( ) ; 
 
         c o u t   < <   " a p m :   "   < <   a p m * 6 0   < <   e n d l   < <   e n d l ; 
 } 
 
