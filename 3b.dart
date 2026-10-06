import 'package:flutter/material.dart'; 
void main() { runApp(MyApp()); } 
class MyApp extends StatelessWidget { 
@override 
Widget build(BuildContext context) { 
return MaterialApp( 
home: MyHomePage() 
); 
} 
} 
class MyHomePage extends StatelessWidget { 
@override 
Widget build(BuildContext context) { 
return Scaffold( 
appBar: AppBar( 
title: Text("Flutter Row Example"), 
), 
body: Row( 
mainAxisAlignment: MainAxisAlignment.spaceEvenly, 
children:<Widget>[ 
Container( 
margin: EdgeInsets.all(12.0), 
padding: EdgeInsets.all(8.0), 
decoration:BoxDecoration( 
borderRadius:BorderRadius.circular(8), 
color:Colors.green 
), 
child: 
Text("React.js",style: TextStyle(color:Colors.yellowAccent,fontSize:25),), 
), 
Container( 
margin: EdgeInsets.all(15.0), 
padding: EdgeInsets.all(8.0), 
decoration:BoxDecoration( 
borderRadius:BorderRadius.circular(8), 
color:Colors.green 
), 
TextStyle(color:Colors.yellowAccent,fontSize:25),), 
), 
Container( 
margin: EdgeInsets.all(12.0), 
padding: EdgeInsets.all(8.0), 
decoration:BoxDecoration( 
borderRadius:BorderRadius.circular(8), 
color:Colors.green 
), 
TextStyle(color:Colors.yellowAccent,fontSize:25),), 
) 
] 
), 
); 
} 
}
