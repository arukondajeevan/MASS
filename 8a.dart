import 'package:flutter/material.dart';
void main() => runApp(const MyApp());
class MyApp extends StatelessWidget {
const MyApp({super.key});
@override
Widget build(BuildContext context) {
return const MaterialApp(
debugShowCheckedModeBanner: false,
home: AnimatedForm(),
);
}
}
class AnimatedForm extends StatefulWidget {
const AnimatedForm({super.key});
@override
State<AnimatedForm> createState() => _AnimatedFormState();
}
class _AnimatedFormState extends State<AnimatedForm> {
bool show = false;
final nameCtrl = TextEditingController();
@override
void initState() {
super.initState();
Future.delayed(const Duration(milliseconds: 300), () {
setState(() => show = true);
});
}
@override
Widget build(BuildContext context) {
return Scaffold(
appBar: AppBar(title: const Text("Animated Form")),
body: Center(
child: AnimatedScale(
duration: const Duration(milliseconds: 600),
scale: show ? 1 : 0,
curve: Curves.elasticOut,
child: Column(
mainAxisSize: MainAxisSize.min,
children: [
TextField(
controller: nameCtrl,
decoration: const InputDecoration(labelText: "Name"),
),
const SizedBox(height: 16),
ElevatedButton(
onPressed: () {
ScaffoldMessenger.of(context).showSnackBar(
SnackBar(content: Text("Hello, ${nameCtrl.text}!")),
);
},
child: const Text("Submit"),
),
],
),
),
),
);
}
}
