using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotateAround : MonoBehaviour {

	public float speed = 10;
	public Transform target;

	private Vector3 zAxis = new Vector3(0, 0, 1);

	void Start () 
	{
		
	}

	void FixedUpdate () 
	{
		transform.RotateAround(target.position, zAxis, speed); 
	}
}
